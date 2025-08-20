#include "app/ui/RemoveHoldingPage.hpp"

#include <iostream>
#include <string>

#include <app/ui/MenuPage.hpp>
#include <core/Holding.hpp>
#include <core/Portfolio.hpp>

namespace app::ui
{
    void RemoveHoldingPage::render()
    {
        system("clear");
        std::cout << "############################" << std::endl;
        std::cout << "| Welcome in TrackInvests! |" << std::endl;
        std::cout << "############################" << std::endl;
        std::cout << "|      Remove Holding      |" << std::endl;
        std::cout << "############################" << std::endl;
    }

    void RemoveHoldingPage::handle_input()
    {
        int choice;
        std::cout << "Choose holding to remove:" << std::endl;
        int index = 1;
        for (auto& holding : portfolio_->get_holdings())
            std::cout << "[" << index++ << "]: " << holding.to_string() << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;

        std::cout << "\n[1] Confirm removal  [2] Cancel\nChoice: ";
        int confirm;
        std::cin >> confirm;
        if (confirm == 1) {
            portfolio_->remove_holding(portfolio_->get_holdings().at(choice - 1).get_id());
            std::cout << "Holding removed.\n";
        } else {
            std::cout << "Aborted. No changes made.\n";
        }
        next_page_ = nullptr; // Do not use unique_ptr<IPage>(menu_page_)
    }

    std::unique_ptr<IPage> RemoveHoldingPage::next_page()
    {
        return std::move(next_page_);
    }

    void RemoveHoldingPage::set_portfolio(core::Portfolio* portfolio)
    {
        this->portfolio_ = portfolio;
    }
}