#pragma once

#include <string>

#include "io/JsonSerializer.hpp"


namespace io
{
    class ConfigSerializer : public JsonSerializer
    {
    public:
        virtual ~ConfigSerializer() = default;
        void load(const std::string& path) override;
        void save(const std::string& path) override;
        const std::string& get_key() const;
    
    private:
        std::string api_key_;
    };
}