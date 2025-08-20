#include "io/DataSerializer.hpp"

#include <iostream>
#include <fstream>

#include "core/Holding.hpp"

namespace io
{
    DataSerializer::~DataSerializer() {}

    void DataSerializer::load(const std::string& path)
    {
        data_.clear();

        auto portfolio_file = std::ifstream{path};

        if (!portfolio_file.is_open())
        {
            throw std::runtime_error("Could not open file!");
        }

        auto portfolio_data = Json{};
        try 
        {
            portfolio_data = Json::parse(portfolio_file);
        } catch (Json::parse_error& e)
        {
            throw std::runtime_error("Failed to parse file!");
        }

        if (!portfolio_data.contains("portfolios"))
        {
            throw std::runtime_error("Data file does not contain information about portfolios!");
        }

        for (auto& portfolio : portfolio_data["portfolios"])
        {
            data_.push_back(std::make_unique<core::Portfolio>(std::string{portfolio["name"]}));
            
            for (auto& holding: portfolio["holdings"])
            {
                auto date_stream = std::istringstream(std::string{holding["date"]});
                auto date = std::chrono::year_month_day{};
                date_stream >> std::chrono::parse("%F", date);
                
                data_[data_.size() - 1]->add_holding(
                    core::Holding(holding["symbol"], holding["quantity"], holding["price"], date));
            }
        }
    }

    void DataSerializer::save(const std::string& path)
    {
        auto portfolioData = Json{};
        portfolioData["portfolios"] = Json::array();

        for (const auto& portfolioPtr : data_)
        {
            auto portfolioJson = Json{};
            portfolioJson["name"] = portfolioPtr->get_name();
            portfolioJson["holdings"] = Json::array();

            for (const auto& holding : portfolioPtr->get_holdings())
            {
                auto holdingJson = Json{};
                holdingJson["symbol"] = holding.get_symbol();
                holdingJson["quantity"] = holding.get_quantity();
                holdingJson["price"] = holding.get_purchase_price();

                auto dateStream = std::ostringstream{};
                auto date = holding.get_purchase_date();
                dateStream << std::format("{:%F}", date);
                holdingJson["date"] = dateStream.str();

                portfolioJson["holdings"].push_back(holdingJson);
            }
            portfolioData["portfolios"].push_back(portfolioJson);
        }
        auto outfile = std::ofstream{path};
        if (!outfile.is_open())
        {
            throw std::runtime_error("Could not open file with given path!");
        }
        outfile << portfolioData.dump(4);
    }

    std::vector<PortfolioPtr>& DataSerializer::get_data()
    {
        return data_;
    }

} // namespace io