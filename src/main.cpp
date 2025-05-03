#include <iostream>

#include "api/AlphaVantageClient.hpp"

int main()
{
    std::string symbol = "IVV";
    auto alphaVantageClient = api::AlphaVantageClient();
    std::cout << alphaVantageClient.fetch_latest_price(symbol) << std::endl;
    return 0;
}