set(SERVICE_SOURCES
    PortfolioValuationService.cpp
)

add_library(service STATIC ${SERVICE_SOURCES})

target_link_libraries(service PUBLIC 
    api    
    core)

target_include_directories(service
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(core PROPERTIES
    LINKER_LANGUAGE CXX
)