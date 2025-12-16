cmake_minimum_required(VERSION 4.0)
project(wpo12 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo12 main.c
        password.c
        oefeningen.c
        trampoline.h)
