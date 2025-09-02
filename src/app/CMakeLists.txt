set(APP_SOURCES
    App.cpp
    ui/AddHoldingPage.cpp
    ui/EditHoldingPage.cpp
    ui/MenuPage.cpp
    ui/PortfolioPage.cpp
    ui/RemoveHoldingPage.cpp
    ui/SearchSymbolPage.cpp
    ui/AddBondPage.cpp
)

add_library(app STATIC ${APP_SOURCES})

target_link_libraries(app PUBLIC
    api    
    core
    io
    service
)

target_include_directories(app
    PUBLIC
        ${CMAKE_SOURCE_DIR}/include
)

set_target_properties(core PROPERTIES
    LINKER_LANGUAGE CXX
)