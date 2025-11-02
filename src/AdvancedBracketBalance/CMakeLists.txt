add_library(stack stack.c)

add_executable(advancedBracketBalance advancedBracketBalance.c)

target_link_libraries(advancedBracketBalance PRIVATE stack)
