cmake_minimum_required(VERSION 3.16)
project(proyecto3 C)

set(CMAKE_C_STANDARD 99)

include_directories(src headers)

add_executable(proyecto3
        src/main.c
        src/hash_table.c
        headers/hash_table.h
        headers/threadville_map.h src/threadville_map.c headers/utils.h src/utils.c headers/linked_list.h src/linked_list.c headers/vehicle.h src/vehicle.c headers/threadville_maintenance.h src/threadville_maintenance.c)


target_link_libraries(proyecto3 pthread)
target_link_libraries(proyecto3 m)
