cmake_minimum_required(VERSION 4.0)
project(wpo9 C)

set(CMAKE_C_STANDARD 99)

add_executable(wpo9 main.c
        max_value_node.c
        generic_tree_insert_node.c
        balanced_brackets.c
        stack.h
        stack.c
        generic_queue.c
        delete_node.c
        generic_linked_list.c)
