import config

from bfs import BreadthFirstSearch


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


if __name__ == "__main__":
    import sys

    print("GraphTheory Algorithms")
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <input_file_path>")
        sys.exit(1)

    input_file_path = sys.argv[1]
    test_breadth_first_search(input_file_path)
