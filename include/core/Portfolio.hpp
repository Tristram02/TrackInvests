#pragma once

#include <vector>
#include <string>
#include "core/Holding.hpp"
#include "core/Bond.hpp"

namespace core
{

class Portfolio
{
public:
    Portfolio(const std::string& name);
    
    void add_holding(const Holding& holding);
    void remove_holding(const std::string& id);
    void clear();

    const std::vector<Holding>& get_holdings() const;
    std::vector<Holding>& get_holdings();
    double get_total_initial_cost() const;
    double get_total_current_value() const;
    double get_total_profit_loss() const;
    double get_total_profit_los_percent() const;

    const std::string& get_name() const;

    void set_name(const std::string& newName);

    void add_bond(const Bond& bond);
    void remove_bond(const std::string& symbol);
    const std::vector<Bond>& get_bonds() const;
    std::vector<Bond>& get_bonds();

private:
    std::string name_;
    std::vector<Holding> holdings_;
    std::vector<Bond> bonds_;
};
} // core