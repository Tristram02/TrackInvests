#pragma once

#include <string>

namespace api
{
    class ApiClient
    {
    
    public:
        virtual ~ApiClient() = default;
        virtual double fetch_latest_price(const std::string& symbol) const = 0;
    };
}