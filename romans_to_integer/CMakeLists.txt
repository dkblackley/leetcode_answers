cmake_minimum_required(VERSION 3.24)
project(romans_to_integer)

#set(CMAKE_CXX_STANDARD 98)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(romans_to_integer main.cpp)
