add_executable(sortingStation sortingStation.c)

add_library(stack stack.c)

target_link(sortingStation PRIVATE stack)
