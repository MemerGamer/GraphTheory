class FordFulkerson:
    def __init__(self, V):
        self.V = V
        self.capacity = [[0] * V for _ in range(V)]
        self.residual_capacity = [[0] * V for _ in range(V)]
        self.visited = [False] * V
        self.parent = [-1] * V

    def addEdge(self, u, v, capacity):
        self.capacity[u][v] = capacity

    def bfs(self, source, drain):
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
        min_capacity = float("inf")
        current = v
        while current != u:
            previous = self.parent[current]
            min_capacity = min(min_capacity, self.residual_capacity[previous][current])
            current = previous
        return min_capacity

    def updateResidualCapacity(self, u, v, flow):
        self.residual_capacity[u][v] -= flow
        self.residual_capacity[v][u] += flow

    def maxFlow(self, source, drain):
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
