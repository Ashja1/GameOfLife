cmake_minimum_required(VERSION 2.8)
project(Life)

set(CMAKE_CXX_STANDARD 11) # C++11...
set(CMAKE_CXX_STANDARD_REQUIRED ON) #...is required...
set(CMAKE_CXX_EXTENSIONS OFF) #...without compiler extensions like gnu++11

include_directories(src)
include_directories(lib)

add_subdirectory(src)
add_subdirectory(test)
