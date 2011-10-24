cmake_minimum_required(VERSION 2.8.0)

project(test)

find_package(Qt4 REQUIRED)

set(test_SOURCES Component.cpp SpecializedComponent.cpp Node.cpp main.cpp)
set(test_HEADERS Component.hpp SpecializedComponent.hpp Node.hpp)
qt4_wrap_cpp(test_HEADERS_MOC ${test_HEADERS})
include(${QT_USE_FILE})
add_definitions(-g -std=c++0x ${QT_DEFINITIONS})
add_executable(test.bin ${test_SOURCES} ${test_HEADERS_MOC})
target_link_libraries(test.bin ${QT_LIBRARIES})
