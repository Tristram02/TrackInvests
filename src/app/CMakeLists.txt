set(APP_SOURCES
    App.cpp
)

add_library(app STATIC ${APP_SOURCES})

target_link_libraries(app PUBLIC 
    core 
    api)

target_include_directories(app
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(core PROPERTIES
    LINKER_LANGUAGE CXX
)