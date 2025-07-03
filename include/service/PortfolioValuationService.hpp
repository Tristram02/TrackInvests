#pragma once

#include "api/AlphaVantageClient.hpp"
#include "core/Portfolio.hpp"

namespace service
{

class PortfolioValuationService
{
public:
    static void update_holdings_with_latest_prices(
        core::Portfolio& portfolio, 
        const api::AlphaVantageClient& client);
};

}// namespace service