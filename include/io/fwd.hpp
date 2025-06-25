#pragma once
#include <memory>

namespace io { class ConfigSerializer; }

typedef std::unique_ptr<io::ConfigSerializer> ConfigPtr;