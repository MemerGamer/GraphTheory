# Default Convention

Each input file follows a convention:

```text 
[number of nodes] [number of edges]
[node 1] [node 2] 
[node 2] [node 3]
...
```

## If there are weights

```text
[number of nodes] [number of edges]
[node 1] [node 2] [weight]
[node 2] [node 3] [weight]
...
```

## If there are source and drain nodes

```text
[number of nodes] [number of edges]
[source node] [drain node]
[node 1] [node 2] [weight]
[node 2] [node 3] [weight]
...
```