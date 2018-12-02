cmake_minimum_required(VERSION 3.12)
project(cdm2)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(third-party)
add_subdirectory(utils)
add_subdirectory(test)

#add_executable(cdm2 main.cpp)