#include "app/ui/PortfolioPage.hpp"

#include <iostream>

#include <app/ui/MenuPage.hpp>
#include <core/Portfolio.hpp>
#include <core/Holding.hpp>

namespace app::ui
{
    void PortfolioPage::set_portfolio(core::Portfolio* portfolio)
    {
        this->portfolio_ = portfolio;
    }

    void PortfolioPage::render()
    {
        system("clear");
        std::cout << "############################" << std::endl;
        std::cout << "|      Portfolio Value     |" << std::endl;
        std::cout << "############################" << std::endl;
        if (portfolio_) {
            std::cout << "Portfolio: " << portfolio_->get_name() << std::endl;
            std::cout << "Initial cost: " << portfolio_->get_total_initial_cost() << std::endl;
            std::cout << "Current value: " << portfolio_->get_total_current_value() << std::endl;
            std::cout << "Profit/Loss: " << portfolio_->get_total_profit_loss() << std::endl;
            std::cout << "Profit/Loss (%): " << portfolio_->get_total_profit_los_percent() << "%" << std::endl;
            std::cout << "----------------------------" << std::endl;
            int idx = 1;
            for (auto& holding : portfolio_->get_holdings()) {
                std::cout << "[" << idx++ << "] " << holding.to_string() << std::endl;
            }
        }
    }

    void PortfolioPage::handle_input()
    {
        std::cout << "[1] Back to menu\nChoice: ";
        int choice;
        std::cin >> choice;
        next_page_ = std::make_unique<MenuPage>();
    }

    std::unique_ptr<IPage> PortfolioPage::next_page()
    {
        return std::move(next_page_);
    }
}