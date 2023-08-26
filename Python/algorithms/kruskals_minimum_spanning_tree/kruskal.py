class Kruskal:
    class Edge:
        def __init__(self, source, destination, weight):
            """
            Constructor for the Edge class.

            :param source: The source vertex of the edge.
            :param destination: The destination vertex of the edge.
            :param weight: The weight of the edge.
            """
            self.source = source
            self.destination = destination
            self.weight = weight

    def __init__(self, number_of_nodes):
        """
        Constructor for the Kruskal class.

        :param number_of_nodes: The number of nodes in the graph.
        """
        self.number_of_nodes = number_of_nodes
        self.edges = []
        self.parent = list(range(number_of_nodes + 1))
        self.rank = [0] * (number_of_nodes + 1)

    def add_edge(self, source, destination, weight):
        """
        Add an edge to the graph.

        :param source: The source vertex of the edge.
        :param destination: The destination vertex of the edge.
        :param weight: The weight of the edge.
        """
        self.edges.append(self.Edge(source, destination, weight))

    def find(self, node):
        """
        Find the representative (root) of the set containing a node using path compression.

        :param node: The node whose representative is to be found.
        :return: The representative (root) of the set containing the node.
        """
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def union_set(self, first_node, second_node):
        """
        Union two sets represented by their representatives (roots).

        :param first_node: The representative of the first set.
        :param second_node: The representative of the second set.
        """
        first_node_parent = self.find(first_node)
        second_node_parent = self.find(second_node)

        if self.rank[first_node_parent] > self.rank[second_node_parent]:
            self.parent[second_node_parent] = first_node_parent
        elif self.rank[first_node_parent] < self.rank[second_node_parent]:
            self.parent[first_node_parent] = second_node_parent
        else:
            self.parent[first_node_parent] = second_node_parent
            self.rank[second_node_parent] += 1

    @staticmethod
    def compare_edges(first_edge, second_edge):
        """
        Compare two edges based on their weights.

        :param first_edge: The first edge to compare.
        :param second_edge: The second edge to compare.
        :return: True if the weight of the first edge is less than the weight of the second edge, False otherwise.
        """
        return first_edge.weight < second_edge.weight

    def kruskal_mst(self):
        """
        Find the Minimum Spanning Tree (MST) of the graph using Kruskal's algorithm.
        """
        mst = []
        self.edges.sort(key=lambda edge: edge.weight)

        for edge in self.edges:
            if self.find(edge.source) != self.find(edge.destination):
                mst.append(edge)
                self.union_set(edge.source, edge.destination)

        for edge in mst:
            print(edge.source, edge.destination, edge.weight)
