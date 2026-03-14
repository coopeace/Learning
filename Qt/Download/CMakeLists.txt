cmake_minimum_required(VERSION 3.17)
project(Download)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC 0N)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Network)

add_executable(Download main.cpp)

target_link_libraries(Download Qt6::Core Qt6::Network)
