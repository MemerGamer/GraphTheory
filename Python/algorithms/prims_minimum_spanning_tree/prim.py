import heapq


class Prim:
    def __init__(self, V):
        """
        Constructor for the Prim class.

        :param V: The number of vertices in the graph.
        """
        self.V = V
        self.adj = [[] for _ in range(V)]

    def addEdge(self, u, v, weight):
        """
        Add an edge to the graph.

        :param u: The source vertex of the edge.
        :param v: The target vertex of the edge.
        :param weight: The weight/cost associated with the edge.
        """
        self.adj[u].append((v, weight))
        self.adj[v].append((u, weight))

    def primMST(self):
        """
        Find the Minimum Spanning Tree (MST) of the graph using Prim's algorithm.
        """
        key = [float("inf")] * self.V
        parent = [-1] * self.V
        inMST = [False] * self.V

        key[1] = 0  # Start from vertex 1

        minHeap = [(0, 1)]  # (weight, vertex)

        while minHeap:
            weight, u = heapq.heappop(minHeap)

            if inMST[u]:
                continue

            inMST[u] = True

            for v, w in self.adj[u]:
                if not inMST[v] and w < key[v]:
                    key[v] = w
                    parent[v] = u
                    heapq.heappush(minHeap, (key[v], v))

        # Print the MST edges and their weights
        for i in range(2, self.V):
            print(f"Edge: {parent[i]} - {i} Weight: {key[i]}")
