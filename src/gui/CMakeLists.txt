set(CMAKE_AUTOMOC ON)

set(GUI_SOURCES
    MainWindow.cpp
    ${CMAKE_SOURCE_DIR}/include/gui/MainWindow.hpp
)

add_library(gui STATIC ${GUI_SOURCES})

target_include_directories(gui 
    PUBLIC 
        ${CMAKE_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(gui Qt5::Widgets)

set_target_properties(gui PROPERTIES
    LINKER_LANGUAGE CXX
)