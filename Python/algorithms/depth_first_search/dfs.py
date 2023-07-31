class DepthFirstSearch:
    def __init__(self, number_of_nodes):
        self.number_of_nodes = number_of_nodes
        self.adjacency_list = [[] for _ in range(number_of_nodes + 1)]

    def add_edge_directed(self, first_node, second_node):
        self.adjacency_list[first_node].append(second_node)

    def add_edge_nondirected(self, first_node, second_node):
        self.adjacency_list[first_node].append(second_node)
        self.adjacency_list[second_node].append(first_node)

    def depth_first_search(self, start_node):
        visited = [False] * (self.number_of_nodes + 1)
        self._dfs_helper(start_node, visited)
        print()

    def _dfs_helper(self, current_node, visited):
        visited[current_node] = True
        print(current_node, end=" ")

        for neighbor in self.adjacency_list[current_node]:
            if not visited[neighbor]:
                self._dfs_helper(neighbor, visited)
