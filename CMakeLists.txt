cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set the project name
project(DesktopSect)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Set the sources for your application
set(SOURCES
    main.cpp
    mainwindow.cpp
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES} mainwindow.ui)

target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
)

