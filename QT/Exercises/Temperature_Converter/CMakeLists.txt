cmake_minimum_required(VERSION 3.17)
project(Temperature_Converter)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Temperature_Converter main.cpp temperature.cpp temperature.h)

find_package(Qt6 REQUIRED COMPONENTS Core)

target_link_libraries(Temperature_Converter Qt::Core)
