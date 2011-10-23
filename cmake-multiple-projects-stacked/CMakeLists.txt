cmake_minimum_required(VERSION 2.8.0)
project(add-something)

add_subdirectory(lib)

include_directories(${add_SOURCE_DIR})
add_subdirectory(exe)
