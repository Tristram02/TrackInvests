#include <nlohmann/json.hpp>
#include "exceptions/InvalidAction.hpp"

namespace io
{

    using Json = nlohmann::json;

    class JsonSerializer
    {
    public:
        virtual ~JsonSerializer() = default;
        virtual void save(const std::string& path) { throw exceptions::InvalidAction(
            "You can not save this data to file!"); };
        virtual void load(const std::string& path) = 0;
    };
}