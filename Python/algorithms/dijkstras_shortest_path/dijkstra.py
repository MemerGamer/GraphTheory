import heapq


class Dijkstra:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]

    def addEdge(self, u, v, weight):
        self.adj[u].append((v, weight))
        # Comment the line below if it's a directed graph
        self.adj[v].append((u, weight))

    def dijkstra(self, src):
        dist = [float("inf")] * self.V
        visited = [False] * self.V

        dist[src] = 0
        minHeap = [(0, src)]  # (weight, vertex)

        while minHeap:
            weight, u = heapq.heappop(minHeap)

            if visited[u]:
                continue

            visited[u] = True

            for v, w in self.adj[u]:
                if not visited[v] and dist[u] != float("inf") and dist[u] + w < dist[v]:
                    dist[v] = dist[u] + w
                    heapq.heappush(minHeap, (dist[v], v))

        # Print the shortest distances from the source vertex
        print(f"Shortest distances from vertex {src}:")
        for i in range(1, self.V):
            print(f"Vertex {i}: {dist[i]}")
