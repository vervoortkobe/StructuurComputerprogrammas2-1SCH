cmake_minimum_required(VERSION 4.0)
project(wpo2 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo2 main.c fizzbuzz.h
        calc_cosine.h
)
