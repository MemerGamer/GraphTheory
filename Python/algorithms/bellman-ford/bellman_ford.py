class BellmanFord:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def addEdge(self, u, v, weight):
        self.adj[u].append((v, weight))

    def bellmanFord(self, src):
        dist = [float("inf")] * self.V
        dist[src] = 0

        for _ in range(self.V - 1):
            for u in range(self.V):
                for v, w in self.adj[u]:
                    if dist[u] != float("inf") and dist[u] + w < dist[v]:
                        dist[v] = dist[u] + w

        # Check for negative-weight cycles
        for u in range(self.V):
            for v, w in self.adj[u]:
                if dist[u] != float("inf") and dist[u] + w < dist[v]:
                    print("Graph contains negative weight cycle")
                    return False

        # Print the shortest distances from the source vertex
        print(f"Shortest distances from vertex {src}:")
        for i in range(1, self.V):
            print(f"Vertex {i}: {dist[i]}")

        return True
