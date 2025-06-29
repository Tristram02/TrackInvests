#include <iostream>

#include "api/AlphaVantageClient.hpp"
#include "io/DataSerializer.hpp"
#include "app/App.hpp"

int main()
{
    auto app = app::App{};
    app.run();

    // auto data = std::make_unique<io::DataSerializer>();
    // data->load("../data/portfolios.json"); 

    // int portfolio_number = 1;
    // std::string portfolio_name = "New name ";
    // for (auto& portfolio: data->get_data())
    // {
    //     std::cout << "\n############################" << std::endl;
    //     std::cout << "          Portfolio" << std::endl;
    //     std::cout << "Name: " << portfolio->get_name() << std::endl;
    //     std::cout << "Number of holdings: " << portfolio->get_holdings().size() << std::endl;
    //     std::cout << "############################" << std::endl;
    //     for (auto& holding: portfolio->get_holdings())
    //     {
    //         std::cout << "Symbol: " << holding.get_symbol() << std::endl;
    //         std::cout << "Date: " << holding.get_purchase_date() << std::endl;
    //         std::cout << "Price: " << holding.get_purchase_price() << std::endl;
    //         std::cout << "Quantity: " << holding.get_quantity() << std::endl;
    //         std::cout << std::endl;
    //     }
    //     std::cout << std::endl;
    //     portfolio->set_name(portfolio_name + std::to_string(portfolio_number++));
    // }
    
    // data->save("../data/portfolios.json");

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