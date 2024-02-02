cmake_minimum_required(VERSION 3.26)
project(LINKED_LIST)

set(CMAKE_CXX_STANDARD 14)

add_executable(LINKED_LIST
        singly_linkedlist.cpp
        ../Stack/stack_linked_list.cpp)

add_executable(single_linked_list_withmyself single_linked_list_withmyself.cpp)
add_executable(doubly_linked_list doubly_linked_list.cpp)