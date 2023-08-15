class Kruskal:
    class Edge:
        def __init__(self, source, destination, weight):
            self.source = source
            self.destination = destination
            self.weight = weight

    def __init__(self, number_of_nodes):
        self.number_of_nodes = number_of_nodes
        self.edges = []
        self.parent = list(range(number_of_nodes + 1))
        self.rank = [0] * (number_of_nodes + 1)

    def add_edge(self, source, destination, weight):
        self.edges.append(self.Edge(source, destination, weight))

    def find(self, node):
        if self.parent[node] != node:
            self.parent[node] = self.find(self.parent[node])
        return self.parent[node]

    def union_set(self, first_node, second_node):
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
        return first_edge.weight < second_edge.weight

    def kruskal_mst(self):
        mst = []
        self.edges.sort(key=lambda edge: edge.weight)

        for edge in self.edges:
            if self.find(edge.source) != self.find(edge.destination):
                mst.append(edge)
                self.union_set(edge.source, edge.destination)

        for edge in mst:
            print(edge.source, edge.destination, edge.weight)
