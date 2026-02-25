cmake_minimum_required(VERSION 3.17)
project(Temperature_iterator)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Temperature_iterator temperature.h temperature.cpp main.cpp)

find_package(Qt6 REQUIRED COMPONENTS Core)

target_link_libraries(Temperature_iterator Qt6::Core)
