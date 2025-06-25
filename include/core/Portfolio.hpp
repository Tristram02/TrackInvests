#pragma once

#include <vector>
#include <string>
#include "core/Holding.hpp"

namespace core
{

class Portfolio
{
public:
    Portfolio(const std::string& name);
    
    void add_holding(const Holding& holding);
    void clear();

    const std::vector<Holding>& get_holdings() const;
    std::vector<Holding>& get_holdings();
    double get_total_initial_cost() const;
    double get_total_current_value() const;
    double get_total_profit_loss() const;
    double get_total_profit_los_percent() const;

    const std::string& get_name() const;

private:
    std::string name_;
    std::vector<Holding> holdings_;    
};
} // core