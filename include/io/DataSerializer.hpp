#pragma once

#include <vector>

#include "core/fwd.hpp"
#include "core/Portfolio.hpp"
#include "io/JsonSerializer.hpp"

namespace io
{
    class DataSerializer : public JsonSerializer
    {
    public:
        virtual ~DataSerializer();
        void load(const std::string& path) override;
        void save(const std::string& path) override;
        std::vector<PortfolioPtr>& get_data();

    private:
        std::vector<PortfolioPtr> data_;
    };
}