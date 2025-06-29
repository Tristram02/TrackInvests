#pragma once

#include <string>

#include "api/fwd.hpp"
#include "core/fwd.hpp"
#include "io/fwd.hpp"

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
        void display_menu();
        
        AlphaVantageClientPtr client_api_;
        std::string portfolio_path_;
        DataSerializerPtr data_;
    };
}