#include "core/Portfolio.hpp"

#include <cmath>
#include <limits>
#include <numeric>
#include <chrono>

namespace core
{
    Portfolio::Portfolio(const std::string& name) : name_{std::move(name)}
    {}

    void Portfolio::add_holding(const Holding& holding)
    {
        holdings_.push_back(holding);
    }

    void Portfolio::add_bond(const Bond& bond)
    {
        bonds_.push_back(bond);
    }

    void Portfolio::clear()
    {
        holdings_.clear();
        bonds_.clear();
    }

    const std::vector<Holding>& Portfolio::get_holdings() const
    {
        return holdings_;
    }

    std::vector<Holding>& Portfolio::get_holdings()
    {
        return holdings_;
    }

    const std::vector<Bond>& Portfolio::get_bonds() const
    {
        return bonds_;
    }

    std::vector<Bond>& Portfolio::get_bonds()
    {
        return bonds_;
    }

    double Portfolio::get_total_initial_cost() const
    {
        double holding_cost = std::accumulate(holdings_.begin(), holdings_.end(), 0.0,
            [](double sum, const Holding& h) {
                return sum + h.get_initial_cost();
            });
        double bond_cost = std::accumulate(bonds_.begin(), bonds_.end(), 0.0,
            [](double sum, const Bond& b) {
                return sum + b.get_face_value() * b.get_quantity();
            });
        return holding_cost + bond_cost;
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

        auto now = std::chrono::system_clock::now();
        auto today = std::chrono::year_month_day{std::chrono::floor<std::chrono::days>(now)};
        for (const auto& b : bonds_)
        {
            total_value += b.get_current_value(today);
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

    void Portfolio::set_name(const std::string& newName)
    {
        name_ = newName;
    }

    void Portfolio::remove_holding(const std::string& id)
    {
        auto it = std::remove_if(holdings_.begin(), holdings_.end(), [&](const Holding& h) {
            return h.get_id() == id;
        });
        holdings_.erase(it, holdings_.end());
    }

    void Portfolio::remove_bond(const std::string& symbol)
    {
    }

} // namespace core