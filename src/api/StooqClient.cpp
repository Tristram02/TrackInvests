#include "api/StooqClient.hpp"

#include <exception>
#include <iostream>
#include <memory>
#include <regex>
#include <stdexcept>

#include <api/HttpUtils.hpp>

namespace api
{
    double StooqClient::fetch_latest_price(const std::string& symbol) const
    {
        auto url = std::string{"https://stooq.com/q/l/?s="} + symbol + "&f=sd2t2ohlcv&h&e=csv";
        auto csv_data = HttpUtils::http_get_raw(url);

        auto ss = std::istringstream(csv_data);
        auto line = std::string();

        std::getline(ss, line);
        if (!std::getline(ss, line))
        {
            throw std::runtime_error("No data returned from Stooq!");
        }

        auto columns = std::vector<std::string>();
        auto line_ss = std::stringstream(line);
        auto cell = std::string();
        while (std::getline(line_ss, cell, ','))
        {
            columns.push_back(cell);
        }

        if (columns.size() < 7)
        {
            throw std::runtime_error("Unexpected CSV format!");
        }

        try {
            return std::stod(columns[6]);
        } catch (const std::exception& e) {
            throw std::runtime_error("Failed to parse price!");
        }
    }

    SymbolSearchResults StooqClient::search_symbol(const std::string& keywords) const
    {
        auto url = std::string{"https://stooq.com/q/?s="} + keywords;
        auto html = HttpUtils::http_get_raw(url);
        SymbolSearchResults results;

        std::regex row_regex(R"(<a href=\"/q/\?s=([^\"]+)\">([^<]+)</a>)");
        auto begin = std::sregex_iterator(html.begin(), html.end(), row_regex);
        auto end = std::sregex_iterator();
        for (auto it = begin; it != end; ++it) {
            std::string symbol = (*it)[1].str();
            std::string name = (*it)[2].str();
            results.emplace_back(symbol, name);
        }
        return results;
    }
}