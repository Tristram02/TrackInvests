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

    void MenuPage::handle_input()
    {
        int choice;
        std::cin >> choice;
        switch (choice)
        {
        case 1:
            if (data_serializer_) {
                data_serializer_->load("../data/portfolios.json");
                if (!data_serializer_->get_data().empty()) {
                    portfolio_ = std::move(data_serializer_->get_data().front().get());
                    std::cout << "Wallet loaded!\n";
                } else {
                    portfolio_ = nullptr;
                    std::cout << "No wallet found!\n";
                }
            }
            break;
        case 2:
            if (data_serializer_ && portfolio_) {
                data_serializer_->save("../data/portfolios.json");
                std::cout << "Wallet saved!\n";
            } else {
                std::cout << "No wallet to save!\n";
            }
            break;
        case 3: {
            auto page = std::make_unique<PortfolioPage>();
            page->set_portfolio(portfolio_);
            next_page_ = std::move(page);
            break;
        }
        case 4: {
            auto page = std::make_unique<AddHoldingPage>();
            page->set_portfolio(portfolio_);
            next_page_ = std::move(page);
            break;
        }
        case 5: {
            auto page = std::make_unique<EditHoldingPage>();
            page->set_portfolio(portfolio_);
            next_page_ = std::move(page);
            break;
        }
        case 6: {
            auto page = std::make_unique<RemoveHoldingPage>();
            page->set_portfolio(portfolio_);
            next_page_ = std::move(page);
            break;
        }
        case 7:
            next_page_ = std::make_unique<SearchSymbolPage>();
            break;
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