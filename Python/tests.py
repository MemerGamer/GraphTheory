import config
from enum import Enum
from bfs import BreadthFirstSearch
from dfs import DepthFirstSearch
from prufer import Prufer
from kruskal import Kruskal


def tests(input_file_path, selected_tests):
    for test_type in selected_tests:
        test_type = test_type.upper()
        if test_type == "BFS":
            test_breadth_first_search(input_file_path)
        elif test_type == "DFS":
            test_depth_first_search(input_file_path)
        elif test_type == "PRUFER":
            test_prufer(input_file_path)
        elif test_type == "KRUSKAL":
            test_kruskal(input_file_path)
        elif test_type == "ALL":
            test_breadth_first_search(input_file_path)
            test_depth_first_search(input_file_path)
            test_prufer(input_file_path)
            test_kruskal(input_file_path)
        else:
            print(f"Unknown or incorrect test type: {test_type}")
            print("Available test types:")
            print("ALL, BFS, DFS, PRUFER, KRUSKAL")


def test_breadth_first_search(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())

        graph = BreadthFirstSearch(number_of_nodes)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            # skip empty lines
            line = line.strip()  # Read the line
            # print(line)  # Print the line to verify the contents
            first_node, second_node = map(int, line.split())  # Use the line
            graph.add_edge_nondirected(
                first_node, second_node
            )  # graph.add_edge_directed(first_node, second_node)  # for directed graph

    start_node = 1
    print("BFS traversal starting from node", start_node, ": ", end="")
    graph.breadth_first_search(start_node)
    print()


def test_depth_first_search(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())

        graph = DepthFirstSearch(number_of_nodes)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            # skip empty lines
            line = line.strip()  # Read the line
            # print(line)  # Print the line to verify the contents
            first_node, second_node = map(int, line.split())  # Use the line
            graph.add_edge_nondirected(
                first_node, second_node
            )  # graph.add_edge_directed(first_node, second_node)  # for directed graph

    start_node = 1
    print("DFS traversal starting from node", start_node, ":", end=" ")
    graph.depth_first_search(start_node)


def test_prufer(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())

        prufer_tree = Prufer(number_of_nodes)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            # skip empty lines
            line = line.strip()  # Read the line
            # print(line)  # Print the line to verify the contents
            first_node, second_node = map(int, line.split())  # Use the line
            prufer_tree.add_edge_nondirected(first_node, second_node)

        print("Prufer sequence:", end=" ")
        prufer_sequence = prufer_tree.encode_tree()
        print(" ".join(map(str, prufer_sequence)))

        print("Decoded Prufer sequence:", end=" ")
        decoded_edges = prufer_tree.decode_prufer_sequence()
        for edge in decoded_edges:
            print(f"({edge[0]}, {edge[1]})", end=" ")
        print()


def test_kruskal(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())

        kruskal_mst = Kruskal(number_of_nodes)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            # skip empty lines
            line = line.strip()  # Read the line
            # print(line)  # Print the line to verify the contents
            first_node, second_node, weight = map(int, line.split())  # Use the line
            kruskal_mst.add_edge(first_node, second_node, weight)

        print("Kruskal MST:")
        kruskal_mst.kruskal_mst()
        print()
