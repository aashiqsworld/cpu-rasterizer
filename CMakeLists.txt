cmake_minimum_required(VERSION 3.26)
project(cpu_rasterizer)

set(CMAKE_CXX_STANDARD 14)

add_executable(cpu_rasterizer
        main.cc
        bitmap.h)
