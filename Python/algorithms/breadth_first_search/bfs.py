from collections import deque


class BreadthFirstSearch:
    def __init__(self, number_of_nodes):
        self.number_of_nodes = number_of_nodes
        # Adjust for 1-based indexing
        self.adjacency_list = [[] for _ in range(number_of_nodes + 1)]

    def add_edge_directed(self, first_node, second_node):
        self.adjacency_list[first_node].append(second_node)

    def add_edge_nondirected(self, first_node, second_node):
        self.adjacency_list[first_node].append(second_node)
        self.adjacency_list[second_node].append(first_node)

    def breadth_first_search(self, start_node):
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
