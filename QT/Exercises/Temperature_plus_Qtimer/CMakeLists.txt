
cmake_minimum_required(VERSION 3.17)
project(Temperature_plus_Qtimer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(Tempearture_plus_Qtimer main.cpp temperature.h)

find_package(Qt6 REQUIRED COMPONENTS Core)

target_link_libraries(Tempearture_plus_Qtimer Qt::Core)
