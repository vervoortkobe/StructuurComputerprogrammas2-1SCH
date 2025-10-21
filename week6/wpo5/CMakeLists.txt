cmake_minimum_required(VERSION 4.0)
project(wpo5 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo5 main.c
        flatten.h
        substring.h
        increment_day.h
        encode_decode.h
        encode_piece_decode_piece.h
        calc_difference.h
)
