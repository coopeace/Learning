cmake_minimum_required(VERSION 3.16)
project(HelloWorldGui)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets)

add_executable(HelloWorldGui main.cpp)

target_link_libraries(HelloWorldGui Qt6::Core Qt6::Widgets)
