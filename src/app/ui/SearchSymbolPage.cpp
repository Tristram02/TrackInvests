#include "app/ui/SearchSymbolPage.hpp"

#include <iostream>

namespace app::ui
{
    void SearchSymbolPage::render()
    {
        system("clear");
        std::cout << "=== Search Symbol ===" << std::endl;
        std::cout << "Enter symbol or company name: ";
    }

    void SearchSymbolPage::handle_input()
    {
        std::string query;
        std::cin >> query;
    }
}