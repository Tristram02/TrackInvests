#pragma once
#include <memory>

namespace io { class ConfigSerializer; }
namespace io { class DataSerializer; }

typedef std::unique_ptr<io::ConfigSerializer> ConfigPtr;
typedef std::unique_ptr<io::DataSerializer> DataSerializerPtr;