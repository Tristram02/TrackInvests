#include "service/PortfolioValuationService.hpp"

namespace service
{
    void PortfolioValuationService::update_holdings_with_latest_prices(
        core::Portfolio& portfolio,
        const api::AlphaVantageClient& client)
    {
        for (auto& holding : portfolio.get_holdings())
        {
            double latest_price = client.fetch_latest_price(holding.get_symbol());
            holding.set_current_price(latest_price);
        }
    }
}