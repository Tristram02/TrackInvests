#pragma once

#include <nlohmann/json.hpp>
#include <string>

namespace api 
{
    using Json = nlohmann::json;

    class HttpUtils
    {
    public:
        static Json http_get(const std::string& url);
        static std::string http_get_raw(const std::string& url);
    };

}