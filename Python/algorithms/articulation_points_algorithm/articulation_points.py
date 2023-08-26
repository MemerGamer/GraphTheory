class ArticulationPoints:
    def __init__(self, V):
        """
        Constructor for the ArticulationPoints class.

        :param V: The number of vertices in the graph.
        """
        self.V = V
        self.adj = [[] for _ in range(V)]
        self.visited = [False] * V
        self.discTime = [-1] * V
        self.lowTime = [-1] * V
        self.parent = [-1] * V
        self.isArticulationPoint = [False] * V
        self.time = 0

    def addEdge(self, u, v):
        """
        Add an edge to the graph.

        :param u: The source vertex of the edge.
        :param v: The target vertex of the edge.
        """
        self.adj[u].append(v)
        self.adj[v].append(u)

    def dfs(self, u):
        """
        Depth-First Search (DFS) function for finding articulation points.

        :param u: The current vertex being visited.
        """
        children = 0
        self.visited[u] = True
        self.discTime[u] = self.lowTime[u] = self.time
        self.time += 1

        for v in self.adj[u]:
            if not self.visited[v]:
                children += 1
                self.parent[v] = u
                self.dfs(v)
                self.lowTime[u] = min(self.lowTime[u], self.lowTime[v])

                if self.parent[u] == -1 and children > 1:
                    self.isArticulationPoint[u] = True

                if self.parent[u] != -1 and self.lowTime[v] >= self.discTime[u]:
                    self.isArticulationPoint[u] = True
            elif v != self.parent[u]:
                self.lowTime[u] = min(self.lowTime[u], self.discTime[v])

    def findArticulationPoints(self):
        """
        Find articulation points in the graph.
        """
        for i in range(self.V):
            if not self.visited[i]:
                self.dfs(i)

    def printArticulationPoints(self):
        """
        Print the detected articulation points in the graph.
        """
        print("Articulation points:", end=" ")
        for i in range(self.V):
            if self.isArticulationPoint[i]:
                print(i, end=" ")
        print()
