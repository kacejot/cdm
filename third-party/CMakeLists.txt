cmake_minimum_required(VERSION 3.5)
project(third-party)

if (MSVC)
    option(gtest_force_shared_crt "" ON)
endif()

add_subdirectory(googletest)