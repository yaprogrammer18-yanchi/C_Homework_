add_library(list list.c)

add_executable(sortedList 
    sortedList.c 
    testSortedList.c
)
target_link_libraries(sortedList PRIVATE list)

