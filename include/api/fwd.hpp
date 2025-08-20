#pragma once
#include <memory>

namespace api
{
    class AlphaVantageClient;
    class StooqClient;
    class YahooFinanceClient;
}

typedef std::unique_ptr<api::AlphaVantageClient> AlphaVantageClientPtr;
typedef std::unique_ptr<api::StooqClient> StooqClientPtr;
typedef std::unique_ptr<api::YahooFinanceClient> YahooFinanceClientPtr;