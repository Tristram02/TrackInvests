#include "core/Holding.hpp"

#include <cmath>
#include <limits>
#include <stdexcept>

namespace core
{
    
    Holding::Holding(const std::string& symbol, const double& quantity,
        const double& purchase_price, const Date& purchase_date) :
        symbol_{std::move(symbol)},
        quantity_{quantity},
        purchase_price_{purchase_price},
        purchase_date_{std::move(purchase_date)}
    {
        if (symbol_.empty())
        {
            throw std::invalid_argument("Holding symbol cannot be empty!");
        }
    
        if (quantity_ <= 0)
        {
            throw std::invalid_argument("Holding quantity cannot be smaller or equal to 0!");
        }
    
        if (purchase_price_ < 0)
        {
            throw std::invalid_argument("Holding purchase price must be greater than 0");
        }
    }
    
    const std::string& Holding::get_symbol() const
    {
        return this->symbol_;
    }
    
    double Holding::get_quantity() const
    {
        return this->quantity_;
    }
    
    double Holding::get_purchase_price() const
    {
        return this->purchase_price_;
    }
    
    const Date& Holding::get_purchase_date() const
    {
        return this->purchase_date_;
    }

    double Holding::get_initial_cost() const
    {
        return quantity_ * purchase_price_;
    }

    double Holding::get_current_price() const
    {
        return current_price_;
    }

    double Holding::get_current_value() const
    {
        if (std::isnan(current_price_))
        {
            return std::numeric_limits<double>::quiet_NaN();
        }
        return quantity_ * current_price_;
    }

    double Holding::get_profit_loss() const
    {
        if (std::isnan(current_price_))
        {
            return std::numeric_limits<double>::quiet_NaN();
        }
        return get_current_value() - get_initial_cost();
    }

    double Holding::get_profit_loss_percent() const
    {
        double initial_cost = get_initial_cost();
        if (initial_cost == 0.0 || std::isnan(current_price_))
        {
            return std::numeric_limits<double>::quiet_NaN();
        }
        return (get_profit_loss() / initial_cost) * 100.0;
    }

    void Holding::set_current_price(double price)
    {
        current_price_ = price;
    }

} // core

