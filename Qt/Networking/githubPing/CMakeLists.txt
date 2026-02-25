cmake_minimum_required(VERSION 3.17)
project(Networking)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(githubPing main.cpp)

find_package(Qt6 REQUIRED COMPONENTS Core Network)

target_link_libraries(githubPing Qt6::Core Qt6::Network)
