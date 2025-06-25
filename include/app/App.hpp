#pragma once

#include <string>

#include "api/fwd.hpp"
#include "core/fwd.hpp"

namespace app
{
    class App
    {
    public:
        void run();
    
    private:
        bool load_portfolio();
        bool update_prices();
        void display_results();
        
        AlphaVantageClientPtr client_api_;
        PortfolioPtr portfolio_;
        std::string portfolio_path_;
    };
}