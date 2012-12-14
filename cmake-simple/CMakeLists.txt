cmake_minimum_required(VERSION 2.8.0)

project(test)

#find_package(some-package REQUIRED)

set(test_SOURCES main.cpp)
set(test_HEADERS header.hpp)

#include(${some-package-INCLUDE_DIRS})

add_definitions(-g -std=c++11 -Wall -Wextra)
add_executable(test.bin ${test_SOURCES} ${test_HEADERS_MOC})
target_link_libraries(test.bin ${some-package-LIBRARIES})
