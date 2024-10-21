cmake_minimum_required(VERSION 3.14)

# Set the project name
project(DesktopSect)

# Find the Qt 6 packages you need
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Set the sources for your application
set(SOURCES
    main.cpp
    mainwindow.cpp
)

# Add the executable
add_executable(${PROJECT_NAME} ${SOURCES} mainwindow.ui)

# Link the Qt libraries
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)

# Enable the MOC (Meta-Object Compiler) feature
set_target_properties(${PROJECT_NAME} PROPERTIES
    AUTOMOC ON
    AUTOUIC ON
)

