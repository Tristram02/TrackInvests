set(CORE_SOURCES
    Holding.cpp
    Portfolio.cpp
)

add_library(core STATIC ${CORE_SOURCES})

target_include_directories(core
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(core PROPERTIES
    LINKER_LANGUAGE CXX
)