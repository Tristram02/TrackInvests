#include "app/ui/ManuPage.hpp"

#include <iostream>

#include <app/ui/SearchSymbolPage.hpp>

namespace app::ui
{

    void MenuPage::render()
    {
        system("clear");
        std::cout << "############################" << std::endl;
        std::cout << "| Welcome in TrackInvests! |" << std::endl;
        std::cout << "############################" << std::endl;
        std::cout << "|           MENU           |" << std::endl;
        std::cout << "|[1] Load wallet           |" << std::endl;
        std::cout << "|[2] Save wallet           |" << std::endl;
        std::cout << "|[3] Buy holding           |" << std::endl;
        std::cout << "|[4] Sell holding          |" << std::endl;
        std::cout << "|[5] Search symbol         |" << std::endl;
        std::cout << "|[6] Exit                  |" << std::endl;
        std::cout << "############################" << std::endl;
    }

    void MenuPage::handle_input()
    {
        int choice;
        std::cin >> choice;

        switch (choice)
        {
        case 5:
            next_page_ = std::make_unique<SearchSymbolPage>();
            return;
        
        default:
            return;
        }
    }

    std::unique_ptr<IPage> MenuPage::next_page()
    {
        return std::move(next_page_);
    }
}