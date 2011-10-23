cmake_minimum_required(VERSION 2.8.0)

project(test)

find_package(Qt4 REQUIRED)

set(test_SOURCES main.cpp)
set(test_HEADERS header.hpp)
set(QT_USE_QTSCRIPT TRUE)
qt4_wrap_cpp(test_HEADERS_MOC ${test_HEADERS})
include(${QT_USE_FILE})
add_definitions(${QT_DEFINITIONS})
add_definitions(-g -std=c++0x)
add_executable(test.bin ${test_SOURCES} ${test_HEADERS_MOC})
target_link_libraries(test.bin ${QT_LIBRARIES} yaml-cpp)
