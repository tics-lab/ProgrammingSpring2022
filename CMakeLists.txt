cmake_minimum_required(VERSION 3.21)
project(ProgrammingSpring2022)

set(CMAKE_CXX_STANDARD 14)

include_directories(Task6)

add_executable(ProgrammingSpring2022
        Task6/Class_description.h
        Task6/Class_method.cpp)