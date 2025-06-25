#include "io/DataSerializer.hpp"

#include <iostream>
#include <fstream>

#include "core/Holding.hpp"

namespace io
{
    void DataSerializer::load(const std::string& path)
    {
        auto portfolio_file = std::ifstream{path};

        if (!portfolio_file.is_open())
        {
            throw std::runtime_error("Could not open config file!");
        }

        auto portfolio_data = Json{};
        try 
        {
            portfolio_data = Json::parse(portfolio_file);
        } catch (Json::parse_error& e)
        {
            throw std::runtime_error("Failed to parse config file!");
        }

        if (!portfolio_data.contains("portfolios"))
        {
            throw std::runtime_error("Data file does not contain information about portfolios!");
        }

        std::cout << "Gdzieś tam jesteśmy" << std::endl;

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

    }

    const std::vector<PortfolioPtr>& DataSerializer::get_data() const
    {
        return data_;
    }

} // namespace io