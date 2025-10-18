cmake_minimum_required(VERSION 4.0)
project(wpo4 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo4 main.c
        my_and_or.h
        my_strrchr.h
        my_strpbrk.h
        my_strcmp.h
        string_span.h)
