#pragma once

#include "api/fwd.hpp"
#include "core/fwd.hpp"

namespace service
{

class PortfolioValuationService
{
public:
    static void update_holdings_with_latest_prices(
        core::Portfolio* portfolio, 
        api::StooqClient* client);
};

}// namespace service