cmake_minimum_required(VERSION 3.16)

project(TrackInvests VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)


find_package(CURL REQUIRED)
find_package(nlohmann_json 3 REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(/usr/include/boost)
find_package(Qt5 REQUIRED COMPONENTS Widgets)

add_subdirectory(src/gui)
add_subdirectory(src/core)
add_subdirectory(src/api)
add_subdirectory(src/io)
add_subdirectory(src/app)
add_subdirectory(src/service)

add_executable(track_invests
    src/main.cpp
)

target_link_libraries(track_invests PRIVATE
  core
  api
  io
  app
  service
  gui
  CURL::libcurl
  nlohmann_json::nlohmann_json
  Qt5::Widgets
)

target_include_directories(track_invests PRIVATE include)