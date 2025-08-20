#include "app/ui/EditHoldingPage.hpp"

#include <iostream>
#include <string>

#include <app/ui/MenuPage.hpp>
#include <core/Portfolio.hpp>
#include <core/Holding.hpp>

namespace app::ui
{
    void EditHoldingPage::set_portfolio(core::Portfolio* portfolio)
    {
        this->portfolio_ = portfolio;
    }

    void EditHoldingPage::render()
    {
        system("clear");
        std::cout << "############################" << std::endl;
        std::cout << "|      Edit Holding        |" << std::endl;
        std::cout << "############################" << std::endl;
        int idx = 1;
        for (auto& holding : portfolio_->get_holdings()) {
            std::cout << "[" << idx++ << "] " << holding.to_string() << std::endl;
        }
    }

    void EditHoldingPage::handle_input()
    {
        int choice;
        std::cout << "Choose holding to edit: ";
        std::cin >> choice;
        if (choice < 1 || choice > (int)portfolio_->get_holdings().size()) {
            std::cout << "Invalid choice.\n";
            next_page_ = std::make_unique<MenuPage>();
            return;
        }
        auto& holding = portfolio_->get_holdings().at(choice - 1);

        double new_quantity = holding.get_quantity();
        double new_price = holding.get_purchase_price();
        std::string new_date;
        bool valid = false;

        while (!valid) {
            std::cout << "New quantity [" << holding.get_quantity() << "]: ";
            std::string input;
            std::getline(std::cin >> std::ws, input);
            if (!input.empty()) {
                try { new_quantity = std::stod(input); } catch (...) { std::cout << "Invalid!\n"; continue; }
            }
            std::cout << "New purchase price [" << holding.get_purchase_price() << "]: ";
            std::getline(std::cin, input);
            if (!input.empty()) {
                try { new_price = std::stod(input); } catch (...) { std::cout << "Invalid!\n"; continue; }
            }
            std::cout << "New date [YYYY-MM-DD]: ";
            std::getline(std::cin, new_date);
            valid = true;
        }

        std::cout << "\n[1] Confirm  [2] Cancel\nChoice: ";
        int confirm;
        std::cin >> confirm;
        if (confirm == 1) {
            holding.set_quantity(new_quantity);
            holding.set_purchase_price(new_price);
            if (!new_date.empty()) {
                std::istringstream date_stream(new_date);
                core::Date date;
                date_stream >> std::chrono::parse("%F", date);
                holding.set_purchase_date(date);
            }
        } else {
            std::cout << "Aborted. No changes made.\n";
        }
        next_page_ = nullptr; // Do not use unique_ptr<IPage>(menu_page_)
    }

    std::unique_ptr<IPage> EditHoldingPage::next_page()
    {
        return std::move(next_page_);
    }
}