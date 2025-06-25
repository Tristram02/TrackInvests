#pragma once
#include <memory>

namespace api
{
    class AlphaVantageClient;
}

typedef std::unique_ptr<api::AlphaVantageClient> AlphaVantageClientPtr;