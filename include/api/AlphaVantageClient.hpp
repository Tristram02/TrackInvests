#pragma once

#include <nlohmann/json_fwd.hpp>
#include <string>
#include <nlohmann/json.hpp>

#include "api/ApiClient.hpp"
#include "io/ConfigSerializer.hpp"
#include "io/fwd.hpp"

namespace api
{
    using Json = nlohmann::json;

    class AlphaVantageClient : public ApiClient
    {

    public:
        AlphaVantageClient();
        double fetch_latest_price(const std::string& symbol) const override;

    private:
        Json http_get(const std::string& url) const;
        double parse_price_from_json(const Json& data, const std::string& symbol) const;
        std::string api_key_;
        ConfigPtr config_;
    };
}