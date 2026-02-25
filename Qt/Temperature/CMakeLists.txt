cmake_minimum_required(VERSION 3.17)
project(Temperature)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Temperature temperature.h main.cpp)

find_package(Qt6 REQUIRED COMPONENTS Core)

target_link_libraries(Temperature Qt6::Core)
