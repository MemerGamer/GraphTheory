# Graph Theory Algorithms

This repository contains implementations of various graph theory algorithms. These algorithms are commonly taught in university courses and can be used to solve a variety of problems related to graphs.

## Algorithms and Programming Languages

If a box is checked, the algorithm has been implemented in that language.

| Algorithm                                        | C++                | Python             | TypeScript         | Rust | Go  | Zig | V   | Java | Kotlin | C#  | Ruby |
| ------------------------------------------------ | ------------------ | ------------------ | ------------------ | ---- | --- | --- | --- | ---- | ------ | --- | ---- |
| Breadth-First Search (BFS)                       | :heavy_check_mark: | :heavy_check_mark: | :heavy_check_mark: |      |     |     |     |      |        |     |      |
| Depth-First Search (DFS)                         | :heavy_check_mark: | :heavy_check_mark: |                    |      |     |     |     |      |        |     |      |
| Prufer Encode & Decode                           | :heavy_check_mark: | :heavy_check_mark: |                    |      |     |     |     |      |        |     |      |
| Check if a Graph is Bipartite (Colorable)        | :heavy_check_mark: | :heavy_check_mark: |                    |      |     |     |     |      |        |     |      |
| Articulation Points (or Cut Vertices) in a Graph | :heavy_check_mark: | :heavy_check_mark: |                    |      |     |     |     |      |        |     |      |
| Bridge detection algorithm                       | :heavy_check_mark: | :heavy_check_mark: |                    |      |     |     |     |      |        |     |      |
| Kruskal's Minimum Spanning Tree Algorithm        | :heavy_check_mark: | :heavy_check_mark: |                    |      |     |     |     |      |        |     |      |
| Prim's Minimum Spanning Tree Algorithm           | :heavy_check_mark: | :heavy_check_mark: |                    |      |     |     |     |      |        |     |      |
| Dijkstra's Shortest Path Algorithm               | :heavy_check_mark: | :heavy_check_mark: |                    |      |     |     |     |      |        |     |      |
| Bellman-Ford Algorithm                           | :heavy_check_mark: | :heavy_check_mark: |                    |      |     |     |     |      |        |     |      |
| Ford Fulkerson Algorithm                         | :heavy_check_mark: | :heavy_check_mark: |                    |      |     |     |     |      |        |     |      |
| Floyd-Warshall Algorithm                         | :heavy_check_mark: | :heavy_check_mark: |                    |      |     |     |     |      |        |     |      |

## Getting Started

To use these algorithms, you'll need to have a basic understanding of graph theory and programming in either C++ or Python.
Each algorithm is contained in its own folder and the corresponding files and can be run independently.

## Prerequisites

To run the C++ implementations, you'll need a C++ compiler installed on your system. The code has been tested with g++ on Linux. To run the Python implementations, you'll need Python 3 installed.

## Installing

To use these algorithms, simply clone this repository to your local machine:

```console
git clone https://github.com/MemerGamer/GraphTheory.git
```

## Usage

Each algorithm is contained in its own folder and file and can be run independently.
To use an algorithm, simply navigate to the corresponding folder and files and run it using the appropriate command for your language.

There are also tests for each algorithm, these are automatically run if you run the main.cpp file in the root directory for C++ or the main.py file in the root directory for Python.

## Tests

| Algorithm           | C++              | Python           | Input file                |
| ------------------- | ---------------- | ---------------- | ------------------------- |
| BFS                 | 0.000040 seconds | 0.000153 seconds | default-input-04.txt      |
| DFS                 | 0.000065 seconds | 0.000182 seconds | default-input-04.txt      |
| Prufer              | 0.000100 seconds | 0.000203 seconds | default-input-06.txt      |
| Bipartite           | 0.000059 seconds | 0.000167 seconds | default-input-07.txt      |
| Articulation Points | 0.000098 seconds | 0.000217 seconds | default-input-08.txt      |
| Bridges             | 0.000064 seconds | 0.000176 seconds | default-input-10.txt      |
| Kruskal             | 0.000176 seconds | 0.000525 seconds | weighted-input-09.txt     |
| Prim                | 0.000525 seconds | 0.000529 seconds | weighted-input-09.txt     |
| Dijkstra            | 0.000221 seconds | 0.000604 seconds | weighted-input-09.txt     |
| Bellman-Ford        | 0.000326 seconds | 0.000965 seconds | weighted-input-09.txt     |
| Ford-Fulkerson      | 0.000104 seconds | 0.000219 seconds | source-drain-input-01.txt |
| Floyd-Warshall      | 0.000083 seconds | 0.000225 seconds | weighted-input-12.txt     |

The test were run on an Asus Vivobook Pro 15 with an Intel® Core™ i5-7300HQ × 4 processor and 16GB of RAM on Fedora 38.
The results may vary depending on your system.
