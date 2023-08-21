class ArticulationPoints:
    def __init__(self, V):
        self.V = V
        self.adj = [[] for _ in range(V)]
        self.visited = [False] * V
        self.discTime = [-1] * V
        self.lowTime = [-1] * V
        self.parent = [-1] * V
        self.isArticulationPoint = [False] * V
        self.time = 0

    def addEdge(self, u, v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def dfs(self, u):
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
        for i in range(self.V):
            if not self.visited[i]:
                self.dfs(i)

    def printArticulationPoints(self):
        print("Articulation points:", end=" ")
        for i in range(self.V):
            if self.isArticulationPoint[i]:
                print(i, end=" ")
        print()
