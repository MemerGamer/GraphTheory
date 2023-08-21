class FloydWarshall:
    def __init__(self, V):
        self.V = V
        self.dist = [[float("inf")] * V for _ in range(V)]
        for i in range(V):
            self.dist[i][i] = 0

    def addEdge(self, u, v, w):
        self.dist[u][v] = w

    def floydWarshall(self):
        for k in range(self.V):
            for i in range(self.V):
                for j in range(self.V):
                    if (
                        self.dist[i][k] != float("inf")
                        and self.dist[k][j] != float("inf")
                        and self.dist[i][k] + self.dist[k][j] < self.dist[i][j]
                    ):
                        self.dist[i][j] = self.dist[i][k] + self.dist[k][j]

    def printShortestPaths(self):
        for i in range(1, self.V):
            for j in range(self.V):
                if self.dist[i][j] == float("inf"):
                    print("INF", end=" ")
                else:
                    print(self.dist[i][j], end=" ")
            print()
