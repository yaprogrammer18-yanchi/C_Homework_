add_library(list list.c)

add_library(cyclicList cyclicList.c)

add_executable(counting counting.c)

add_executable(sortedListTask sortedListTask.c)

target_link_libraries(sortedListTask PRIVATE list)

target_link_libraries(counting PRIVATE cyclicList)