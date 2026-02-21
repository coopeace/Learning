cmake_minimum_required(VERSION 3.17)
project(Signal_Slot)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(Qt6 REQUIRED COMPONENTS Core)

add_executable(Signal_Slot main.cpp sender.cpp receiver.cpp sender.h receiver.h)

target_link_libraries(Signal_Slot Qt::Core)
