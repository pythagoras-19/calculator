cmake_minimum_required(VERSION 3.26)
project(calculator)

set(CMAKE_CXX_STANDARD 17)
find_package(Qt5Widgets REQUIRED)

add_executable(calculator main.cpp
        Calculator.cpp
        Calculator.h
        Animal.cpp
        Animal.h)
target_link_libraries(calculator Qt5::Widgets)