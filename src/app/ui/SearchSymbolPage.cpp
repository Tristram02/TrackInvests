#include "app/ui/SearchSymbolPage.hpp"

#include <iostream>

#include <api/AlphaVantageClient.hpp>
#include <api/StooqClient.hpp>
#include <app/ui/MenuPage.hpp>

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
        auto client = api::StooqClient();
        auto results = client.search_symbol(query);
        std::cout << "Results:" << std::endl;
        for (const auto& result : results)
        {
            std::cout << "Symbol: " << result.first << ", Name: " << result.second << std::endl;
        }
        std::cout << "\n[1] Search again  [2] Return to menu\nChoice: ";
        int choice = 0;
        std::cin >> choice;
        if (choice == 1) {
            return;
        } else {
            next_page_ = nullptr; // Do not use unique_ptr<IPage>(menu_page_)
        }
    }

    std::unique_ptr<IPage> SearchSymbolPage::next_page()
    {
        return std::move(next_page_);
    }
}