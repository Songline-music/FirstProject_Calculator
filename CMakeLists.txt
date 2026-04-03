cmake_minimum_required(VERSION 3.16)
project(CalculatorUI LANGUAGES CXX RC)

if(MSVC)
    add_compile_options(/utf-8)
endif()

include(qt.cmake)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR}
    COMPONENTS
        Core
        Gui
        Widgets
)
qt_standard_project_setup()

set(PROJECT_SOURCES
    Main/main.cpp

    UI/CalculatorUI.ui

    UI/CalculatorUI.hpp
    UI/CalculatorUI.cpp

    UI/CalculatorUIHelpers.hpp
    UI/CalculatorUIHelpers.cpp

    UI/CalculatorInputController.cpp
    UI/WindowChromeController.cpp
    UI/PanelController.cpp
    UI/ModeDrawerController.cpp
    UI/UiEventFilterController.cpp

    Resources/resources.qrc
    Resources/app.rc
)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})

qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

set_target_properties(${PROJECT_NAME}
    PROPERTIES
        WIN32_EXECUTABLE TRUE
)

target_link_libraries(${PROJECT_NAME}
    PUBLIC
        Qt::Core
        Qt::Gui
        Qt::Widgets
)