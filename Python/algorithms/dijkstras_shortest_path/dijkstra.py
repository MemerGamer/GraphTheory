import heapq


class Dijkstra:
    def __init__(self, V):
        """
        Constructor for the Dijkstra class.

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
        # Comment the line below if it's a directed graph
        self.adj[v].append((u, weight))

    def dijkstra(self, src):
        """
        Find the shortest paths from a source vertex to all other vertices using Dijkstra's algorithm.

        :param src: The source vertex from which to find shortest paths.
        """
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
