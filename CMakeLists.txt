cmake_minimum_required(VERSION 3.8)
project(Pascal)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Pascal.cpp Pascal.h wci/ wci/frontend/)
add_executable(Pascal ${SOURCE_FILES})