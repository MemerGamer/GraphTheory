from collections import deque


class BreadthFirstSearch:
    def __init__(self, number_of_nodes):
        """
        Constructor for the BFSGraph class.

        :param number_of_nodes: The number of nodes in the graph.
        """
        self.number_of_nodes = number_of_nodes
        self.adjacency_list = [
            [] for _ in range(number_of_nodes + 1)
        ]  # Adjust for 1-based indexing

    def add_edge_directed(self, first_node, second_node):
        """
        Add a directed edge to the graph.

        :param first_node: The source node of the edge.
        :param second_node: The destination node of the edge.
        """
        self.adjacency_list[first_node].append(second_node)

    def add_edge_nondirected(self, first_node, second_node):
        """
        Add a nondirected edge to the graph.

        :param first_node: The first node of the edge.
        :param second_node: The second node of the edge.
        """
        self.adjacency_list[first_node].append(second_node)
        self.adjacency_list[second_node].append(first_node)

    def breadth_first_search(self, start_node):
        """
        Perform Breadth-First Search (BFS) traversal starting from a given node.

        :param start_node: The starting node for BFS traversal.
        """
        visited = [False] * (self.number_of_nodes + 1)  # Track visited nodes
        node_queue = deque()
        node_queue.append(start_node)
        visited[start_node] = True

        while node_queue:
            current_node = node_queue.popleft()
            print(current_node, end=" ")
            for neighbor in self.adjacency_list[current_node]:
                if not visited[neighbor]:
                    visited[neighbor] = True
                    node_queue.append(neighbor)
        print()
