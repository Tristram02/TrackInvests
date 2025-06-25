#pragma once
#include <memory.h>
#include <memory>

namespace core 
{ 
    class Portfolio;
    class Holding;
}

typedef std::unique_ptr<core::Portfolio> PortfolioPtr;
typedef std::unique_ptr<core::Holding> HoldingPtr;