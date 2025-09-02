#include "app/ui/AddBondPage.hpp"
#include <iostream>
#include <string>
#include <chrono>
#include <sstream>
#include <core/Bond.hpp>
#include <core/Portfolio.hpp>
#include <app/ui/MenuPage.hpp>

namespace app::ui {

    void AddBondPage::render() {
        system("clear");
        std::cout << "############################" << std::endl;
        std::cout << "| Welcome in TrackInvests! |" << std::endl;
        std::cout << "############################" << std::endl;
        std::cout << "|        Add Bond          |" << std::endl;
        std::cout << "############################" << std::endl;
    }

    void AddBondPage::handle_input() {
        std::string date;
        double quantity = 0.0, face_value = 0.0, interest_rate = 0.0, inflation_rate = 0.0;
        int years_to_maturity = 0, type_choice = 0;
        bool valid = false;

        while (!valid) {
            std::cout << "\nQuantity: "; if (!(std::cin >> quantity) || quantity <= 0) { std::cout << "Invalid quantity!\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); continue; }
            std::cout << "\nFace Value: "; if (!(std::cin >> face_value) || face_value <= 0) { std::cout << "Invalid face value!\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); continue; }
            std::cout << "\nInterest Rate (e.g. 0.07): "; if (!(std::cin >> interest_rate) || interest_rate < 0) { std::cout << "Invalid interest rate!\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); continue; }
            std::cout << "\nYears to Maturity: "; if (!(std::cin >> years_to_maturity) || years_to_maturity <= 0) { std::cout << "Invalid years!\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); continue; }
            std::cout << "\nBond Type [1=Fixed(TOS), 2=Inflation(EDO)]: "; if (!(std::cin >> type_choice) || (type_choice != 1 && type_choice != 2)) { std::cout << "Invalid type!\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); continue; }
            std::cout << "\nIssue Date [YYYY-MM-DD]: "; std::cin >> date;
            if (type_choice == 2) {
                std::cout << "\nInflation Rate (e.g. 0.05): ";
                if (!(std::cin >> inflation_rate) || inflation_rate < 0) { std::cout << "Invalid inflation rate!\n"; std::cin.clear(); std::cin.ignore(10000, '\n'); continue; }
            }
            valid = true;
        }
        std::cout << "\n[1] Confirm  [2] Cancel  [3] Exit\nChoice: ";
        int choice; std::cin >> choice;
        if (choice == 1) {
            std::istringstream date_stream(date);
            core::Date parsed_date;
            date_stream >> std::chrono::parse("%F", parsed_date);
            core::BondType type = (type_choice == 1) ? core::BondType::FixedRate : core::BondType::InflationIndexed;
            core::Bond bond(quantity, interest_rate, type, parsed_date, years_to_maturity, inflation_rate);
            portfolio_->add_bond(bond);
        } else if (choice == 3) {
            std::cout << "Aborted. No changes made.\n";
            go_back_to_menu_ = true;
        }
    }

    std::unique_ptr<IPage> AddBondPage::next_page() { return std::move(next_page_); }
    void AddBondPage::set_portfolio(core::Portfolio* portfolio) { this->portfolio_ = portfolio; }

}
