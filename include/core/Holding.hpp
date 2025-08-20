#pragma once

#include <string>
#include <chrono>

namespace core
{
using Date = std::chrono::year_month_day;
class Holding
{
public:
        Holding(const std::string& symbol, const double& quantity, 
        const double& purchase_price, const Date& purchase_date);

        const std::string& get_id() const;
        const std::string& get_symbol() const;
        double get_quantity() const;
        double get_purchase_price() const;
        const Date& get_purchase_date() const;

        double get_current_price() const;
        double get_initial_cost() const;
        double get_current_value() const;
        double get_profit_loss() const;
        double get_profit_loss_percent() const;

        void set_current_price(double price);
        void set_quantity(double quantity);
        void set_purchase_price(double price);
        void set_purchase_date(const Date& date);

        std::string to_string();

private:
        std::string id_;    
        std::string symbol_;
        double quantity_;
        double purchase_price_;
        Date purchase_date_;
        double current_price_ = 0.0;
};

}
