cmake_minimum_required(VERSION 4.0)
project(wpo6 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo6 main.c
        lowercase.h
        generate_primes.h
        poly_plus.h
        calculate_all_averages.h)
