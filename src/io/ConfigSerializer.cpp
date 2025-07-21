#include "io/ConfigSerializer.hpp"
#include <fstream>
#include <stdexcept>

namespace io
{
    void ConfigSerializer::load(const std::string& path)
    {
        auto config_file = std::ifstream{path};

        if (!config_file.is_open())
        {
            throw std::runtime_error("Could not open config file!");
        }

        auto config_data = Json{};
        try 
        {
            config_data = Json::parse(config_file);
        } catch (Json::parse_error& e)
        {
            throw std::runtime_error("Failed to parse config file!");
        }

        if (!config_data.contains("av_api_key"))
        {
            throw std::runtime_error("Config file does not contain key!");
        }

        auto key = config_data["av_api_key"].get<std::string>();
        if (key.empty())
        {
            throw std::runtime_error("Key is empty!");
        }

        this->api_key_ = key;
    }

    void ConfigSerializer::save(const std::string& path)
    {

    }

    const std::string& ConfigSerializer::get_key() const
    {
        return this->api_key_;
    } 
}