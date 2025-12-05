cmake_minimum_required(VERSION 3.25)

project(C_Homework C)

add_subdirectory(src/CheckHowLintersWork)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_compile_options(-Wall -Wextra -Wpedantic)