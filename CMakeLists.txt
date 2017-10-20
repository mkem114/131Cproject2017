cmake_minimum_required(VERSION 3.8)
project(131Cproject)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES test_program.c project.c project.h)
add_executable(131Cproject ${SOURCE_FILES})