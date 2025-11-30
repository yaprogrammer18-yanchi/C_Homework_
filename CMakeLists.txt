cmake_minimum_required(VERSION 3.25)

project(C_Homework C)

add_subdirectory(src/TestTask)

enable_testing()

add_compile_options(-Wall -Wextra -Wpedantic)