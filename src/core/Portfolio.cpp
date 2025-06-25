#include "core/Portfolio.hpp"

#include <cmath>
#include <limits>
#include <numeric>

namespace core
{
    Portfolio::Portfolio(const std::string& name) : name_{std::move(name)}
    {}

    void Portfolio::add_holding(const Holding& holding)
    {
        holdings_.push_back(holding);
    }

    void Portfolio::clear()
    {
        holdings_.clear();
    }

    const std::vector<Holding>& Portfolio::get_holdings() const
    {
        return holdings_;
    }

    std::vector<Holding>& Portfolio::get_holdings()
    {
        return holdings_;
    }

    double Portfolio::get_total_initial_cost() const
    {
        return std::accumulate(holdings_.begin(), holdings_.end(), 0.0,
            [](double sum, const Holding& h) {
                return sum + h.get_initial_cost();
            });
    }

    double Portfolio::get_total_current_value() const
    {
        double total_value = 0;
        for (const auto& h : holdings_)
        {
            double current_holding_value = h.get_current_value();
            
            if (std::isnan(current_holding_value))
            {
                return std::numeric_limits<double>::quiet_NaN();
            }
            total_value += current_holding_value;
        }
        return total_value;
    }

    double Portfolio::get_total_profit_loss() const
    {
        double current_value = get_total_current_value();

        if (std::isnan(current_value))
        {
            return std::numeric_limits<double>::quiet_NaN();
        }

        return current_value - get_total_initial_cost();
    }

    double Portfolio::get_total_profit_los_percent() const
    {
        double initial_cost = get_total_initial_cost();
        double profit_loss = get_total_profit_loss();

        if (initial_cost == 0.0 || std::isnan(profit_loss))
        {
            return std::numeric_limits<double>::quiet_NaN();
        }

        return (profit_loss / initial_cost) * 100.0;
    }

    const std::string& Portfolio::get_name() const
    {
        return name_;
    }

} // namespace core