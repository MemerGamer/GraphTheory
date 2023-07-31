cmake_minimum_required(VERSION 3.25)
project(C__)

set(CMAKE_CXX_STANDARD 23)

add_executable(C__ main.cpp breadth-first_search/breadth-first_search.cpp breadth-first_search/breadth-first_search.h useful-includes.h tests.cpp tests.h depth-first_search/depth-first_search.cpp depth-first_search/depth-first_search.h)
