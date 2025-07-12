#include "api/StooqClient.hpp"

#include <exception>
#include <iostream>
#include <memory>
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
}