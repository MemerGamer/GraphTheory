class DepthFirstSearch:
    def __init__(self, number_of_nodes):
        """
        Constructor for the DepthFirstSearch class.

        :param number_of_nodes: The number of nodes in the graph.
        """
        self.number_of_nodes = number_of_nodes
        self.adjacency_list = [[] for _ in range(number_of_nodes + 1)]

    def add_edge_directed(self, first_node, second_node):
        """
        Add a directed edge from the first node to the second node.

        :param first_node: The source node.
        :param second_node: The target node.
        """
        self.adjacency_list[first_node].append(second_node)

    def add_edge_nondirected(self, first_node, second_node):
        """
        Add an undirected edge between two nodes.

        :param first_node: The first node.
        :param second_node: The second node.
        """
        self.adjacency_list[first_node].append(second_node)
        self.adjacency_list[second_node].append(first_node)

    def depth_first_search(self, start_node):
        """
        Perform Depth-First Search (DFS) traversal starting from a given node.

        :param start_node: The starting node for DFS traversal.
        """
        visited = [False] * (self.number_of_nodes + 1)
        self._dfs_helper(start_node, visited)
        print()

    def _dfs_helper(self, current_node, visited):
        """
        Depth-First Search (DFS) helper function.

        :param current_node: The current node being visited.
        :param visited: An array to keep track of visited nodes.
        """
        visited[current_node] = True
        print(current_node, end=" ")

        for neighbor in self.adjacency_list[current_node]:
            if not visited[neighbor]:
                self._dfs_helper(neighbor, visited)
