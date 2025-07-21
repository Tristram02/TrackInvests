#include "app/ui/SearchSymbolPage.hpp"
#include "api/StooqClient.hpp"

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
        api::StooqClient client;
        auto results = client.search_symbol(query);
        std::cout << "Results:" << std::endl;
        for (const auto& result : results)
        {
            std::cout << "Symbol: " << result.first << ", Name: " << result.second << std::endl;
        }
        std::cout << "Press Enter to return to menu...";
        std::cin.ignore();
        std::cin.get();
    }
}