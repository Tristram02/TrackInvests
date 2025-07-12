#pragma once
#include <memory>

namespace api
{
    class AlphaVantageClient;
    class StooqClient;
}

typedef std::unique_ptr<api::AlphaVantageClient> AlphaVantageClientPtr;
typedef std::unique_ptr<api::StooqClient> StooqClientPtr;