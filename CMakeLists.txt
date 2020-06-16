cmake_minimum_required(VERSION 3.16)
project(proyecto3 C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_EXE_LINKER_FLAGS "-rdynamic")

include_directories(src headers)

add_executable(proyecto3
        headers/controller.h
        headers/dict.h
        headers/interface.h
        headers/linked_list_cars.h
        headers/linked_list.h
        headers/hash_table.h
        headers/threadville_map.h
        headers/utils.h
        headers/vehicle.h
        headers/threadville_maintenance.h
        headers/hash_table_street_info.h
        src/main.c
        src/hash_table.c
        src/threadville_map.c
        src/utils.c
        src/linked_list.c
        src/vehicle.c
        src/threadville_maintenance.c
        src/controller.c
        src/dict.c
        src/interface.c
        src/linked_lists_cars.c
        src/hash_table_street_info.c
    )

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

include_directories(${GTK3_INCLUDE_DIRS})
link_directories(${GTK3_LIBRARY_DIRS})

add_definitions(${GTK3_CFLAGS_OTHER})

target_link_libraries(proyecto3 ${GTK3_LIBRARIES})
target_link_libraries(proyecto3 pthread)
target_link_libraries(proyecto3 m)
