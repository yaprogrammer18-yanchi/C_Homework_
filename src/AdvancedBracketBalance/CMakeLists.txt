add_library(stack stack.c)

add_executable(advancedBracketsBalance advancedBracketsBalance.c)

target_link_libraries(advancedBracketsBalance PRIVATE stack)
