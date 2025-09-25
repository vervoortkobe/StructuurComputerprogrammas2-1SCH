cmake_minimum_required(VERSION 4.0)
project(wpo1 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo1 main.c
        squared.c
        oef2.c
        fac.h
        ggd.h
        vkv.h)
