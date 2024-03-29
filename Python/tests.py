import config
from enum import Enum
from bfs import BreadthFirstSearch
from dfs import DepthFirstSearch
from prufer import Prufer
from kruskal import Kruskal
from prim import Prim
from dijkstra import Dijkstra
from bellman_ford import BellmanFord
from ford_fulkerson import FordFulkerson
from floyd_warshall import FloydWarshall
from check_bipartite import CheckBipartite
from articulation_points import ArticulationPoints
from bridge_detection import BridgeDetection


def tests(input_file_path, selected_tests):
    for test_type in selected_tests:
        test_type = test_type.upper()
        if test_type == "BFS":
            test_breadth_first_search(input_file_path)
        elif test_type == "DFS":
            test_depth_first_search(input_file_path)
        elif test_type == "CHECK_BIPARTITE":
            test_check_bipartite(input_file_path)
        elif test_type == "PRUFER":
            test_prufer(input_file_path)
        elif test_type == "KRUSKAL":
            test_kruskal(input_file_path)
        elif test_type == "PRIM":
            test_prim(input_file_path)
        elif test_type == "DIJKSTRA":
            test_dijkstra(input_file_path)
        elif test_type == "BELLMAN_FORD":
            test_bellman_ford(input_file_path)
        elif test_type == "FORD_FULKERSON":
            test_ford_fulkerson(input_file_path)
        elif test_type == "FLOYD_WARSHALL":
            test_floyd_warshall(input_file_path)
        elif test_type == "ARTICULATION_POINTS":
            test_articulation_points(input_file_path)
        elif test_type == "BRIDGES":
            test_bridges(input_file_path)
        elif test_type == "ALL":
            test_breadth_first_search(input_file_path)
            test_depth_first_search(input_file_path)
            test_check_bipartite(input_file_path)
            test_prufer(input_file_path)
            test_kruskal(input_file_path)
            test_prim(input_file_path)
            test_dijkstra(input_file_path)
            test_bellman_ford(input_file_path)
            test_ford_fulkerson(input_file_path)
            test_floyd_warshall(input_file_path)
            test_articulation_points(input_file_path)
            test_bridges(input_file_path)
        else:
            print(f"Unknown or incorrect test type: {test_type}")
            print("Available test types:")
            print(
                "ALL, BFS, DFS, CHECK_BIPARTITE PRUFER, KRUSKAL, PRIM, DIJKSTRA, BELLMAN_FORD, FORD_FULKERSON, FLOYD_WARSHALL"
            )


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


def test_check_bipartite(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())
        check_bipartite = CheckBipartite(number_of_nodes + 1)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            line = line.strip()
            first_node, second_node = map(int, line.split())
            check_bipartite.addEdge(first_node, second_node)

        if check_bipartite.isBipartite():
            print("Graph is bipartite")
        else:
            print("Graph is not bipartite")
        print()


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


def test_prim(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())

        prim_mst = Prim(number_of_nodes + 1)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            # skip empty lines
            line = line.strip()  # Read the line
            # print(line)  # Print the line to verify the contents
            first_node, second_node, weight = map(int, line.split())  # Use the line
            prim_mst.addEdge(first_node, second_node, weight)

        print("Prim MST:")
        prim_mst.primMST()
        print()


def test_dijkstra(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())

        dijkstra_sp = Dijkstra(number_of_nodes + 1)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            # skip empty lines
            line = line.strip()  # Read the line
            # print(line)  # Print the line to verify the contents
            first_node, second_node, weight = map(int, line.split())  # Use the line
            dijkstra_sp.addEdge(first_node, second_node, weight)

        print("Dijkstra SP:")
        dijkstra_sp.dijkstra(1)
        print()


def test_bellman_ford(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())

        bellman_ford_sp = BellmanFord(number_of_nodes + 1)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            # skip empty lines
            line = line.strip()  # Read the line
            # print(line)  # Print the line to verify the contents
            first_node, second_node, weight = map(int, line.split())  # Use the line
            bellman_ford_sp.addEdge(first_node, second_node, weight)

        print("Bellman-Ford SP:")
        bellman_ford_sp.bellmanFord(1)
        print()


def test_ford_fulkerson(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())
        source, drain = map(int, input_file.readline().split())

        ford_fulkerson = FordFulkerson(number_of_nodes + 1)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            # skip empty lines
            line = line.strip()  # Read the line
            # print(line)  # Print the line to verify the contents
            first_node, second_node, weight = map(int, line.split())  # Use the line
            ford_fulkerson.addEdge(first_node, second_node, weight)

        print("Ford-Fulkerson Max Flow:", ford_fulkerson.maxFlow(source, drain))
        print()


def test_floyd_warshall(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())
        floyd_warshall = FloydWarshall(number_of_nodes + 1)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            line = line.strip()
            first_node, second_node, weight = map(int, line.split())
            floyd_warshall.addEdge(first_node, second_node, weight)

        floyd_warshall.floydWarshall()
        print("Floyd-Warshall Shortest Paths:")
        floyd_warshall.printShortestPaths()
        print()


def test_articulation_points(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())
        articulation_points = ArticulationPoints(number_of_nodes + 1)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            line = line.strip()
            first_node, second_node = map(int, line.split())
            articulation_points.addEdge(first_node, second_node)

        articulation_points.findArticulationPoints()
        articulation_points.printArticulationPoints()
        print()


def test_bridges(input_file_path):
    with open(input_file_path, "r") as input_file:
        number_of_nodes, number_of_edges = map(int, input_file.readline().split())
        bridge_detection = BridgeDetection(number_of_nodes + 1)

        for i in range(number_of_edges):
            line = input_file.readline()
            if not line:
                continue
            line = line.strip()
            first_node, second_node = map(int, line.split())
            bridge_detection.add_edge(first_node, second_node)

        bridge_detection.find_bridges()
        bridge_detection.print_bridges()
        print()
