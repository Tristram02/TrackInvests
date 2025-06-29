#include "app/App.hpp"

#include <iostream>

namespace app
{
    
    void App::display_menu()
    {
        system("clear");
        std::cout << "############################" << std::endl;
        std::cout << "| Welcome in TrackInvests! |" << std::endl;
        std::cout << "############################" << std::endl;
        std::cout << "|                          |" << std::endl;
        std::cout << "|           MENU           |" << std::endl;
        std::cout << "|__________________________|" << std::endl;
        std::cout << "|[1] Load wallet           |" << std::endl;
        std::cout << "|[2] Save wallet           |" << std::endl;
        std::cout << "|[3] Buy holding           |" << std::endl;
        std::cout << "|[4] Sell holding          |" << std::endl;
        std::cout << "|[5] Exit                  |" << std::endl;
        std::cout << "|                          |" << std::endl;
        std::cout << "############################" << std::endl;
    }

    void App::run()
    {
        display_menu();
    }

}// namespace app
