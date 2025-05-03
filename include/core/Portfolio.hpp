#pragma once

#include <vector>
#include "core/Holding.hpp"

namespace core
{

class Portfolio
{
public:
    Portfolio() = default;
    
    void add_holding(const Holding& holding);
    void clear();

    const std::vector<Holding>& get_holdings() const;
    std::vector<Holding>& get_holdings();
    double get_total_initial_cost() const;
    double get_total_current_value() const;
    double get_total_profit_loss() const;
    double get_total_profit_los_percent() const;

private:
    std::vector<Holding> holdings_;    
};
} // core