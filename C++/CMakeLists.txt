cmake_minimum_required(VERSION 3.25)
project(C__)

set(CMAKE_CXX_STANDARD 23)

add_executable(C__ main.cpp breadth-first_search/breadth-first_search.cpp breadth-first_search/breadth-first_search.h useful-includes.h tests.cpp tests.h depth-first_search/depth-first_search.cpp depth-first_search/depth-first_search.h prufer_encode_decode/prufer.cpp prufer_encode_decode/prufer.h kruskals_minimum_spanning_tree/kruskal.cpp kruskals_minimum_spanning_tree/kruskal.h
        prims_minimum_spanning_tree/prim.cpp
        prims_minimum_spanning_tree/prim.h
        dijkstras_shortest_path/dijkstra.cpp
        dijkstras_shortest_path/dijkstra.h
        bellman-ford/bellman_ford.cpp
        bellman-ford/bellman_ford.h
        ford_fulkerson/ford_fulkerson.cpp
        ford_fulkerson/ford_fulkerson.h
        floyd-warshall/floyd_warshall.cpp
        floyd-warshall/floyd_warshall.h)
