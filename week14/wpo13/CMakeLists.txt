cmake_minimum_required(VERSION 4.0)
project(wpo13 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo13 main.c
        bitmasks_person.c
        replace_line.c)
