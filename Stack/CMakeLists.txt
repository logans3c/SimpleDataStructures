cmake_minimum_required(VERSION 3.26)
project(Stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(Stack linkedlist.cpp
        stack_linked_list.cpp
        stack_array_based.cpp)

add_executable(stack_array_based stack_array_based.cpp)