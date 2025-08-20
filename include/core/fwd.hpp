#pragma once

#include <memory>

namespace core {
    class Portfolio;
    class Holding;
}

using PortfolioPtr = std::unique_ptr<core::Portfolio>;
using HoldingPtr = std::unique_ptr<core::Holding>;