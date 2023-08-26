class BridgeDetection:
    def __init__(self, V):
        """
        Constructor for the BridgeDetection class.

        :param V: The number of vertices in the graph.
        """
        self.V = V
        self.adj = [[] for _ in range(V)]
        self.visited = [False] * V
        self.discTime = [-1] * V
        self.lowTime = [-1] * V
        self.parent = [-1] * V
        self.bridges = []
        self.time = 0

    def add_edge(self, u, v):
        """
        Constructor for the BridgeDetection class.

        :param V: The number of vertices in the graph.
        """
        self.adj[u].append(v)
        self.adj[v].append(u)

    def find_bridges(self):
        """
        Find bridges in the graph using depth-first search (DFS).
        """
        for i in range(self.V):
            if not self.visited[i]:
                self.dfs(i)

    def print_bridges(self):
        """
        Print the detected bridges in the graph.
        """
        print("Bridges:", end=" ")
        for bridge in self.bridges:
            print(f"{bridge[0]}-{bridge[1]}", end=" ")
        print()

    def dfs(self, u):
        """
        Depth-First Search (DFS) function for finding bridges.

        :param u: The current vertex being visited.
        """
        self.visited[u] = True
        self.discTime[u] = self.lowTime[u] = self.time
        self.time += 1

        for v in self.adj[u]:
            if not self.visited[v]:
                self.parent[v] = u
                self.dfs(v)
                self.lowTime[u] = min(self.lowTime[u], self.lowTime[v])

                if self.lowTime[v] > self.discTime[u]:
                    self.bridges.append((min(u, v), max(u, v)))
            elif v != self.parent[u]:
                self.lowTime[u] = min(self.lowTime[u], self.discTime[v])
