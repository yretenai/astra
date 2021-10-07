cmake_minimum_required(VERSION 3.20)
project(astra_stl)

set(CMAKE_CXX_STANDARD 23)

add_library(astra INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/astra.natvis>)
target_include_directories(astra INTERFACE include)
