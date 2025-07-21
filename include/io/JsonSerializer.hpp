#pragma once

#include <nlohmann/json.hpp>
#include "exceptions/InvalidAction.hpp"

namespace io
{

    using Json = nlohmann::json;

    class JsonSerializer
    {
    public:
        virtual ~JsonSerializer() = default;
        virtual void save(const std::string& path) = 0;
        virtual void load(const std::string& path) = 0;
    };
}