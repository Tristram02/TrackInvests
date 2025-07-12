set(API_SOURCES
    AlphaVantageClient.cpp
    HttpUtils.cpp
    StooqClient.cpp
)

add_library(api STATIC ${API_SOURCES})

target_include_directories(api 
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

target_link_directories(api
    PUBLIC
        core
        CURL::libcurl
        nlohmann_json::nlohmann_json
)

set_target_properties(core PROPERTIES
    LINKER_LANGUAGE CXX
)