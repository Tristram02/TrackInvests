#pragma once

#include <string>

#include <nlohmann/json_fwd.hpp>
#include <nlohmann/json.hpp>

#include "api/ApiClient.hpp"
#include "api/fwd.hpp"
#include "io/ConfigSerializer.hpp"
#include "io/fwd.hpp"

namespace api
{
    using Json = nlohmann::json;

    class StooqClient : public ApiClient
    {

    public:
        double fetch_latest_price(const std::string& symbol) const override;
        std::vector<std::pair<std::string, std::string>> search_symbol(const std::string& keywords) const;

    private:
        Json http_get(const std::string& url) const;
        double parse_price_from_json(const Json& data, const std::string& symbol) const;
        std::string api_key_;
        ConfigPtr config_;
    };
}