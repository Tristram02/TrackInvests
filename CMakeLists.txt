cmake_minimum_required(VERSION 3.16)

project(TrackInvests VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)


find_package(CURL REQUIRED)

find_package(nlohmann_json 3 REQUIRED)

add_executable(track_invests
    src/main.cpp
    src/core/Holding.cpp    
)

target_include_directories(track_invests PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src/include
  )

target_link_libraries(track_invests PRIVATE CURL::libcurl)
target_link_libraries(track_invests PRIVATE nlohmann_json::nlohmann_json)