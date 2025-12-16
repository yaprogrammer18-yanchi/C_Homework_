add_library(listTask list.c)

add_executable(sortedListTask sortedListTask.c)

target_link_libraries(sortedListTask PRIVATE listTask)
