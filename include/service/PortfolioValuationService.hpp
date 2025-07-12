#pragma once

#include "api/StooqClient.hpp"
#include "core/Portfolio.hpp"

namespace service
{

class PortfolioValuationService
{
public:
    static void update_holdings_with_latest_prices(
        core::Portfolio& portfolio, 
        const api::StooqClient& client);
};

}// namespace service