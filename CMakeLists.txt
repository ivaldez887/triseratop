cmake_minimum_required(VERSION 3.27)
project(triseratop C)

set(CMAKE_C_STANDARD 11)

add_executable(triseratop main.c
        bajan.c
        bajan.h
        utils.c
        utils.h
        ploting.c
        ploting.h
)

target_link_libraries(triseratop curl plplot m)

install(TARGETS triseratop DESTINATION /home/fer/.local/bin)
