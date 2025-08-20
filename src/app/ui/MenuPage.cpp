#include "app/ui/MenuPage.hpp"

#include <iostream>

#include <app/ui/SearchSymbolPage.hpp>
#include <app/ui/AddHoldingPage.hpp>
#include <app/ui/EditHoldingPage.hpp>
#include <app/ui/RemoveHoldingPage.hpp>
#include <app/ui/PortfolioPage.hpp>
#include <io/DataSerializer.hpp>



namespace app::ui
{
    void MenuPage::set_data_serializer(io::DataSerializer* data_serializer) {
        data_serializer_ = data_serializer;
    }

    void MenuPage::set_portfolio(core::Portfolio* portfolio) {
        portfolio_ = portfolio;
    }

    void MenuPage::render()
    {
        system("clear");
        std::cout << "############################" << std::endl;
        std::cout << "| Welcome in TrackInvests! |" << std::endl;
        std::cout << "############################" << std::endl;
        std::cout << "|           MENU           |" << std::endl;
        std::cout << "|[1] Load Wallet           |" << std::endl;
        std::cout << "|[2] Save Wallet           |" << std::endl;
        std::cout << "|[3] Show Wallet           |" << std::endl;
        std::cout << "|[4] Add holding           |" << std::endl;
        std::cout << "|[5] Edit holding          |" << std::endl;
        std::cout << "|[6] Remove holding        |" << std::endl;
        std::cout << "|[7] Search symbol         |" << std::endl;
        std::cout << "|[8] Exit                  |" << std::endl;
        std::cout << "############################" << std::endl;
        std::cout << "Current Wallet: ";
        if (portfolio_) {
            std::cout << portfolio_->get_name() << std::endl;
        } else {
            std::cout << "None" << std::endl;
        }
    }

    void MenuPage::print_portfolio_names() const
    {
        if (!data_serializer_) return;
        const auto& portfolios = data_serializer_->get_data();
        std::cout << "Available portfolios:\n";
        int idx = 1;
        for (const auto& portfolio : portfolios) {
            std::cout << "[" << idx++ << "] " << portfolio->get_name() << std::endl;
        }
    }

    core::Portfolio* MenuPage::pick_portfolio() const
    {
        if (!data_serializer_) return nullptr;
        const auto& portfolios = data_serializer_->get_data();
        if (portfolios.empty()) return nullptr;

        int choice = 0;
        std::cout << "Pick portfolio number: ";
        std::cin >> choice;
        if (choice < 1 || choice > (int)portfolios.size()) {
            std::cout << "Invalid choice.\n";
            return nullptr;
        }
        return portfolios[choice - 1].get();
    }

    void MenuPage::handle_input()
    {
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
        {
            if (data_serializer_) {
                data_serializer_->load("../data/portfolios.json");
                auto& portfolios = data_serializer_->get_data();
                if (!portfolios.empty()) {
                    print_portfolio_names();
                    core::Portfolio* selected = pick_portfolio();
                    if (selected) {
                        portfolio_ = selected;
                        set_portfolio(portfolio_);
                        std::cout << "Wallet loaded: " << portfolio_->get_name() << "\n";
                    } else {
                        portfolio_ = portfolios.front().get();
                        set_portfolio(portfolio_);
                        std::cout << "Default wallet loaded: " << portfolio_->get_name() << "\n";
                    }
                } else {
                    portfolio_ = nullptr;
                    set_portfolio(nullptr);
                    std::cout << "No wallet found!\n";
                }
            }
            break;
        }
        case 2:
        {
            if (data_serializer_ && portfolio_) {
                data_serializer_->save("../data/portfolios.json");
                std::cout << "Wallet saved!\n";
            } else {
                std::cout << "No wallet to save!\n";
            }
            break;
        }
        case 3: {
            show_portfolio_ = true;
            break;
        }
        case 4: {
            add_holding_ = true;
            break;
        }
        case 5: {
            edit_holding_ = true;
            break;
        }
        case 6: {
            remove_holding_ = true;
            break;
        }
        case 7: {
            search_symbol_ = true;
            break;
        }
        case 8:
            std::exit(0);
        default:
            std::cout << "Invalid choice. Try again.\n";
            break;
        }
    }

    std::unique_ptr<IPage> MenuPage::next_page()
    {
        return std::move(next_page_);
    }
}