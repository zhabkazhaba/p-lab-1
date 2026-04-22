cmake_minimum_required(VERSION 3.26)
project(sorting_lab)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")

add_executable(sorting_lab
        src/main.cpp
        src/resident.hpp
        src/sort.hpp
        src/util.hpp
)