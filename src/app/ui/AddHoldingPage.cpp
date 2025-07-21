#include "app/ui/AddHoldingPage.hpp"

#include <iostream>
#include <string>
#include <chrono>
#include <sstream>

#include <app/ui/MenuPage.hpp>
#include <core/Holding.hpp>
#include <core/Portfolio.hpp>

namespace app::ui
{
    void AddHoldingPage::render()
    {
        system("clear");
        std::cout << "############################" << std::endl;
        std::cout << "| Welcome in TrackInvests! |" << std::endl;
        std::cout << "############################" << std::endl;
        std::cout << "|        Add Holding       |" << std::endl;
        std::cout << "############################" << std::endl;
    }

    void AddHoldingPage::handle_input()
    {
        double quantity = 0.0, price = 0.0;
        std::string date, symbol;
        bool valid = false;

        while (!valid) {
            std::cout << "\nQuantity [eg. 0.4231]: ";
            if (!(std::cin >> quantity) || quantity <= 0) {
                std::cout << "Invalid quantity!\n";
                std::cin.clear(); std::cin.ignore(10000, '\n');
                continue;
            }
            std::cout << "\nPrice [eg. 12.453]: ";
            if (!(std::cin >> price) || price <= 0) {
                std::cout << "Invalid price!\n";
                std::cin.clear(); std::cin.ignore(10000, '\n');
                continue;
            }
            std::cout << "\nDate [YYYY-MM-DD]: ";
            std::cin >> date;
            std::cout << "\nSymbol: ";
            std::cin >> symbol;
            if (symbol.empty()) {
                std::cout << "Symbol cannot be empty!\n";
                continue;
            }
            valid = true;
        }

        std::cout << "\n[1] Confirm  [2] Cancel\nChoice: ";
        int choice;
        std::cin >> choice;
        if (choice == 1) {
            std::istringstream date_stream(date);
            core::Date parsed_date;
            date_stream >> std::chrono::parse("%F", parsed_date);
            auto holding = core::Holding{symbol, quantity, price, parsed_date};
            portfolio_->add_holding(holding);
        } else {
            std::cout << "Aborted. No changes made.\n";
        }
        next_page_ = std::make_unique<MenuPage>();
    }

    std::unique_ptr<IPage> AddHoldingPage::next_page()
    {
        return std::move(next_page_);
    }

    void AddHoldingPage::set_portfolio(core::Portfolio* portfolio)
    {
        this->portfolio_ = portfolio;
    }
}