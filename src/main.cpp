#include <iostream>

#include "api/AlphaVantageClient.hpp"
#include "io/DataSerializer.hpp"

int main()
{
    auto data = std::make_unique<io::DataSerializer>();
    data->load("../data/portfolios.json"); 

    for (auto& portfolio: data->get_data())
    {
        std::cout << "############################" << std::endl;
        std::cout << "          Portfolio" << std::endl;
        std::cout << "Name: " << portfolio->get_name() << std::endl;
        std::cout << "Number of holdings: " << portfolio->get_holdings().size() << std::endl;
        std::cout << "############################" << std::endl;
        for (auto& holding: portfolio->get_holdings())
        {
            std::cout << "Symbol: " << holding.get_symbol() << std::endl;
            std::cout << "Date: " << holding.get_purchase_date() << std::endl;
            std::cout << "Price: " << holding.get_purchase_price() << std::endl;
            std::cout << "Quantity: " << holding.get_quantity() << std::endl;
            std::cout << std::endl;
        }
        std::cout << std::endl;
    }

    // auto alphaVantageClient = api::AlphaVantageClient();
    // std::string keyword;
    // std::cin >> keyword;
    // std::cout << "Searching for: " << keyword << std::endl;
    // auto results = alphaVantageClient.search_symbol(keyword);
    // for (const auto& result : results)
    // {
    //     std::cout << "Symbol: " << result.first << ", Name: " << result.second << std::endl;
    // }



    // std::cout << alphaVantageClient.fetch_latest_price(results[0].first) << std::endl;

    // std::string symbol = "IVV";
    // std::cout << alphaVantageClient.fetch_latest_price(symbol) << std::endl;
    return 0;
}