#include <exception>
#include <iostream>
#include <memory>
#include <stdexcept>
#include "api/AlphaVantageClient.hpp"
#include "api/HttpUtils.hpp"

namespace api 
{
    AlphaVantageClient::AlphaVantageClient()
    {
        config_ = std::make_shared<io::ConfigSerializer>();
        try {
            config_->load("../config.json");
            api_key_ = config_->get_key();
            if (api_key_.empty())
            {
                throw std::runtime_error("API key loaded from config is empty!");
            }
        } catch(const std::exception& e)
        {
            throw std::runtime_error("Failed to initialize client due to config error: "
                + std::string{e.what()});
        }
    }

    double AlphaVantageClient::fetch_latest_price(const std::string& symbol) const
    {
        auto url = std::string{"https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol="};
        url += symbol;
        url += "&interval=5min&apikey=";
        url += api_key_;
        return parse_price_from_json(http_get(url), symbol);
    }

    Json AlphaVantageClient::http_get(const std::string& url) const
    {
        return HttpUtils::http_get(url);
    }

    double AlphaVantageClient::parse_price_from_json(const Json& data, const std::string& symbol) const
    {
        if (data.contains("Error Message")) {
            std::cerr << "Alpha Vantage API Error for " << symbol << ": " << data["Error Message"].get<std::string>() << std::endl;
            throw std::runtime_error("Alpha Vantage API Error: " + data["Error Message"].get<std::string>());
        }
        if (data.contains("Information")) {
            std::cerr << "Alpha Vantage API Info for " << symbol << ": " << data["Information"].get<std::string>() << std::endl;
            throw std::runtime_error("Alpha Vantage API Info: " + data["Information"].get<std::string>());
        }

        if (!data.contains("Global Quote") || data["Global Quote"].empty()) {
            std::cerr << "Unexpected JSON format: 'Global Quote' object missing or empty for symbol " << symbol << std::endl;
            throw std::runtime_error("Unexpected JSON format: 'Global Quote' missing/empty for " + symbol);
        }

        if (!data["Global Quote"].contains("05. price")) {
            std::cerr << "Unexpected JSON format: '05. price' missing in 'Global Quote' for symbol " << symbol << std::endl;
            throw std::runtime_error("Unexpected JSON format: '05. price' missing for " + symbol);
        }

        auto price_str = data["Global Quote"]["05. price"].get<std::string>();
        return std::stod(price_str);
    }
}