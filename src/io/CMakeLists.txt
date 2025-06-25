set(IO_SOURCES
    ConfigSerializer.cpp
    DataSerializer.cpp
)

add_library(io STATIC ${IO_SOURCES})

target_link_libraries(io PUBLIC core)

target_include_directories(io
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(core PROPERTIES
    LINKER_LANGUAGE CXX
)