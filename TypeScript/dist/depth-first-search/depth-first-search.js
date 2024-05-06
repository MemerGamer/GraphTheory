"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.DFSGraph = void 0;
/**
 * Represents a class for performing Depth-First Search (DFS) on a graph.
 */
class DFSGraph {
    numberOfNodes; // The number of nodes in the graph
    adjacencyList; // Adjacency list representing the graph
    /**
     * Constructor for the DFSGraph class.
     * @param numberOfNodes The number of nodes in the graph.
     */
    constructor(numberOfNodes) {
        this.numberOfNodes = numberOfNodes;
        this.adjacencyList = new Array(numberOfNodes + 1).fill([]);
    }
    /**
     * Add an undirected edge between two nodes in the graph.
     * @param firstNode The first node.
     * @param secondNode The second node.
     */
    addEdgeNonDirected(firstNode, secondNode) {
        this.adjacencyList[firstNode].push(secondNode);
        this.adjacencyList[secondNode].push(firstNode);
    }
    /**
     * Add a directed edge from the first node to the second node in the graph.
     * @param firstNode The source node.
     * @param secondNode The target node.
     */
    addEdgeDirected(firstNode, secondNode) {
        this.adjacencyList[firstNode].push(secondNode);
    }
    /**
     * Perform Depth-First Search (DFS) starting from a specified node.
     * @param startNode The starting node for DFS traversal.
     */
    depthFirstSearch(startNode) {
        const visited = new Array(this.numberOfNodes + 1).fill(false);
        this.dfsHelper(startNode, visited);
        console.log();
    }
    dfsHelper(currentNode, visited) {
        visited[currentNode] = true;
        process.stdout.write(`${currentNode} `);
        for (const neighbor of this.adjacencyList[currentNode]) {
            if (!visited[neighbor]) {
                this.dfsHelper(neighbor, visited);
            }
        }
    }
}
exports.DFSGraph = DFSGraph;
