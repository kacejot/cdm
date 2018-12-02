cmake_minimum_required(VERSION 3.5)
project(utils-test)

file(GLOB SOURCES "./*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES})
target_link_libraries(${PROJECT_NAME} 
    condition
	gtest_main)