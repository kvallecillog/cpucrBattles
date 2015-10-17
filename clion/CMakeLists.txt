cmake_minimum_required(VERSION 3.3)
project(cpucrBattles)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main_mem.cpp module_mem.cpp)
add_executable(cpucrBattles ${SOURCE_FILES})