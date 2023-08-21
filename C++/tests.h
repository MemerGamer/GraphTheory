//
// Created by hunor on 24.05.2023.
//

#ifndef C___TESTS_H
#define C___TESTS_H

#include "useful-includes.h"
#include "breadth-first_search/breadth-first_search.h"
#include "depth-first_search/depth-first_search.h"
#include "prufer_encode_decode/prufer.h"
#include "kruskals_minimum_spanning_tree/kruskal.h"
#include "prims_minimum_spanning_tree/prim.h"
#include "dijkstras_shortest_path/dijkstra.h"

void test_breadth_first_search(const string &input_file_path);

void test_depth_first_search(const string &input_file_path);

void test_prufer(const string &input_file_path);

void test_kruskal(const string &input_file_path);

void test_prim(const string &input_file_path);

void test_dijkstra(const string &input_file_path);
#endif //C___TESTS_H
