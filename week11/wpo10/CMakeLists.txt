cmake_minimum_required(VERSION 4.0)
project(wpo10 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo10 main.c
        count_c.c
        head.c
        grep.c
        database.c)
