cmake_minimum_required(VERSION 3.25)

project(ProgressTest2 C)

add_compile_options(-Wall -Wextra -Wpedantic)

add_executable(main main.c tests.c)

enable_testing()