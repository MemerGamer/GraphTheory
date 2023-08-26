class FordFulkerson:
    def __init__(self, V):
        """
        Constructor for the FordFulkerson class.

        :param V: The number of vertices in the flow network.
        """
        self.V = V
        self.capacity = [[0] * V for _ in range(V)]
        self.residual_capacity = [[0] * V for _ in range(V)]
        self.visited = [False] * V
        self.parent = [-1] * V

    def addEdge(self, u, v, capacity):
        """
        Add an edge with capacity to the flow network.

        :param u: The source vertex of the edge.
        :param v: The target vertex of the edge.
        :param capacity: The capacity of the edge.
        """
        self.capacity[u][v] = capacity

    def bfs(self, source, drain):
        """
        Perform Breadth-First Search (BFS) to find augmenting paths in the residual graph.

        :param source: The source vertex.
        :param drain: The sink (target) vertex.
        :return: True if there is an augmenting path, False otherwise.
        """
        self.visited = [False] * self.V
        queue = [source]
        self.visited[source] = True
        self.parent[source] = -1

        while queue:
            u = queue.pop(0)
            for v in range(self.V):
                if not self.visited[v] and self.residual_capacity[u][v] > 0:
                    queue.append(v)
                    self.parent[v] = u
                    self.visited[v] = True

        return self.visited[drain]

    def minCapacityOnPath(self, u, v):
        """
        Find the minimum capacity on the path from u to v in the residual graph.

        :param u: The source vertex.
        :param v: The target vertex.
        :return: The minimum capacity on the path.
        """
        min_capacity = float("inf")
        current = v
        while current != u:
            previous = self.parent[current]
            min_capacity = min(min_capacity, self.residual_capacity[previous][current])
            current = previous
        return min_capacity

    def updateResidualCapacity(self, u, v, flow):
        """
        Update the residual capacities in the residual graph after augmenting flow.

        :param u: The source vertex.
        :param v: The target vertex.
        :param flow: The flow being added to the edge (u, v).
        """
        self.residual_capacity[u][v] -= flow
        self.residual_capacity[v][u] += flow

    def maxFlow(self, source, drain):
        """
        Find the maximum flow in the flow network using the Ford-Fulkerson algorithm.

        :param source: The source vertex.
        :param drain: The sink (target) vertex.
        :return: The maximum flow value.
        """
        # Initialize residual capacity
        for u in range(self.V):
            for v in range(self.V):
                self.residual_capacity[u][v] = self.capacity[u][v]

        max_flow = 0
        while self.bfs(source, drain):
            flow = self.minCapacityOnPath(source, drain)
            max_flow += flow
            current = drain
            while current != source:
                previous = self.parent[current]
                self.updateResidualCapacity(previous, current, flow)
                current = previous

        return max_flow
