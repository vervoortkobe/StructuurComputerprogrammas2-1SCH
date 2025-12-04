cmake_minimum_required(VERSION 4.0)
project(wpo11 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo11 main.c
        stackmachine_execute_pushint.c
        stackmachine_execute_plus.c
        stackmachine_execute_sub.c
        stackmachine_execute_definetemps_pushtemps.c
        stackmachine_execute_storetemp_pop.c
        stackmachine_execute_call.c
        stackmachine_execute_pusharg_returntop.c)
