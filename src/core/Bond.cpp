#include "core/Bond.hpp"
#include <cmath>
#include <sstream>
#include <iomanip>

namespace core {

Bond::Bond(double quantity,
            double interest_rate,
            BondType type,
            const Date& issue_date,
            int years_to_maturity,
            double inflation_rate)
    : quantity_{quantity},
        interest_rate_{interest_rate},
        type_{type},
        issue_date_{issue_date},
        years_to_maturity_{years_to_maturity},
        inflation_rate_{inflation_rate}
{
    // Basic validation
    if (quantity_ <= 0) throw std::invalid_argument("Bond quantity must be positive!");
    if (interest_rate_ < 0) throw std::invalid_argument("Bond interest rate must be non-negative!");
    if (years_to_maturity_ <= 0) throw std::invalid_argument("Bond years to maturity must be positive!");
    if (type_ == BondType::InflationIndexed && inflation_rate_ < 0) throw std::invalid_argument("Inflation rate must be non-negative!");
}

double Bond::get_quantity() const { return quantity_; }
double Bond::get_face_value() const { return face_value_; }
double Bond::get_interest_rate() const { return interest_rate_; }
BondType Bond::get_type() const { return type_; }
const Date& Bond::get_issue_date() const { return issue_date_; }
int Bond::get_years_to_maturity() const { return years_to_maturity_; }
double Bond::get_inflation_rate() const { return inflation_rate_; }

double Bond::get_current_value(const Date& current_date) const {
    int years_elapsed = (current_date.year() - issue_date_.year()).count();
    if (years_elapsed < 0) years_elapsed = 0;
    if (years_elapsed > years_to_maturity_) years_elapsed = years_to_maturity_;
    double value = 0.0;
    if (type_ == BondType::FixedRate) {
        // TOS
        value = face_value_ * std::pow(1.0 + interest_rate_, years_elapsed);
    } else {
        // EDO
        value = face_value_;
        for (int i = 0; i < years_elapsed; ++i) {
            value *= (1.0 + interest_rate_ + inflation_rate_);
        }
    }
    return value * quantity_;
}

std::string Bond::to_string(const Date& current_date) const {
    std::ostringstream oss;
    oss << "Bond: "
        << ", Type: " << (type_ == BondType::FixedRate ? "TOS (Fixed)" : "EDO (Inflation)")
        << ", Quantity: " << quantity_
        << ", Face Value: " << face_value_
        << ", Interest Rate: " << interest_rate_
        << ", Years to Maturity: " << years_to_maturity_
        << ", Issue Date: " << std::setw(4) << issue_date_.year() << "-" << std::setw(2) << issue_date_.month() << "-" << std::setw(2) << issue_date_.day()
        << ", Current Value: " << get_current_value(current_date);
    if (type_ == BondType::InflationIndexed) {
        oss << ", Inflation Rate: " << inflation_rate_;
    }
    return oss.str();
}

} // namespace core
