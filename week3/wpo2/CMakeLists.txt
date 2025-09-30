cmake_minimum_required(VERSION 4.0)
project(wpo2 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo2 main.c fizzbuzz.h
        print_christmas_tree_oplossing.c
        print_primes.h
        print_perfect_numbers.h
        convert_hex_to_dec.h
        insertion_sort.h
)
