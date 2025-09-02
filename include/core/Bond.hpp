#pragma once
#include "core/fwd.hpp"
#include <string>
#include <memory>
#include <vector>
#include <chrono>

namespace core {

using Date = std::chrono::year_month_day;

enum class BondType {
    FixedRate, // TOS
    InflationIndexed // EDO
};

class Bond {
public:
    Bond(double quantity,
        double interest_rate,
        BondType type,
        const Date& issue_date,
        int years_to_maturity,
        double inflation_rate = 0.0);

    double get_quantity() const;
    double get_face_value() const;
    double get_interest_rate() const;
    BondType get_type() const;
    const Date& get_issue_date() const;
    int get_years_to_maturity() const;
    double get_inflation_rate() const;

    double get_current_value(const Date& current_date) const;
    std::string to_string(const Date& current_date) const;
private:
    double quantity_;
    double face_value_;
    double interest_rate_;
    BondType type_;
    Date issue_date_;
    int years_to_maturity_;
    double inflation_rate_;
};

}// namespace core
