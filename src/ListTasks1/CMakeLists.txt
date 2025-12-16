add_library(listTask OneLinkedList.c)

add_executable(sortedListTask sortedListTask.c)

target_link_libraries(sortedListTask PRIVATE listTask)
