cmake_minimum_required(VERSION 3.24)
project(baca08)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(baca08
        main.cpp
        source.h source.cpp)
