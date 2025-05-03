#include "api/HttpUtils.hpp"

#include <curl/curl.h>
#include <curl/urlapi.h>

namespace api 
{
    size_t WriteCallback(void* contents, size_t size, size_t nmemb,
        void* userp)
    {
        ((std::string*)userp)->append((char*)contents, size * nmemb);
        return size * nmemb;
    }

    Json parse_string_to_json(const std::string& data)
    {
        try 
        {
            return Json::parse(data);
        } catch (Json::parse_error& e) 
        {
            std::string error_msg = "JSON parsing failed: ";
            error_msg += e.what();
            throw std::runtime_error(error_msg);
        }
    }

    Json HttpUtils::http_get(const std::string& url)
    {
        auto readBuffer = std::string{};
        auto res = CURLcode{};
        auto curl = curl_easy_init();

        if (curl)
        {
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
            res = curl_easy_perform(curl);

            if (res != CURLE_OK) {
                std::string error_msg = "HTTP request failed: ";
                error_msg += curl_easy_strerror(res);
                throw std::runtime_error(error_msg + " for URL: " + url);
            }

            curl_easy_cleanup(curl);
            return parse_string_to_json(readBuffer);
        }
        return Json{};
    } 

}
