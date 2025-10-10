cmake_minimum_required(VERSION 4.0)
project(wpo3 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo3 main.c
        convert_whitespace.h
        print_perfect_numbers.h
        rotate.h)
