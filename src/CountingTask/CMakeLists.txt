add_library(cyclicList cyclicList.c)

add_executable(counting counting.c)

target_link_libraries(counting PRIVATE cyclicList)