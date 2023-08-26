from collections import deque


class CheckBipartite:
    def __init__(self, V):
        """
        Constructor for the CheckBipartite class.

        :param V: The number of vertices in the graph.
        """
        self.V = V
        self.adj = [[] for _ in range(V)]

    def addEdge(self, u, v):
        """
        Add an edge to the graph.

        :param u: The source vertex of the edge.
        :param v: The target vertex of the edge.
        """
        self.adj[u].append(v)
        self.adj[v].append(u)

    def isBipartite(self):
        """
        Check if the graph is bipartite using a modified BFS approach.

        :return: True if the graph is bipartite, False otherwise.
        """
        color = [-1] * self.V
        queue = deque()

        for i in range(self.V):
            if color[i] != -1:
                continue  # Skip already colored vertices

            color[i] = 0  # Assign the first color to the source vertex
            queue.append(i)

            while queue:
                u = queue.popleft()

                for v in self.adj[u]:
                    if color[v] == -1:
                        color[v] = 1 - color[u]  # Assign the opposite color
                        queue.append(v)
                    elif color[v] == color[u]:
                        return False  # Found an edge between vertices with the same color, not bipartite

        return True
