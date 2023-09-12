"use strict";
Object.defineProperty(exports, "__esModule", { value: true });
exports.BFSGraph = void 0;
const queue_typescript_1 = require("queue-typescript"); // Import a queue library for TypeScript
/**
 * Represents a class for performing Breadth-First Search (BFS) on a graph.
 */
class BFSGraph {
    numberOfNodes; // The number of nodes in the graph
    adjacencyList; // Adjacency list representing the graph
    /**
     * Constructor for the BFSGraph class.
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
     * Perform Breadth-First Search (BFS) starting from a specified node.
     * @param startNode The starting node for BFS traversal.
     */
    breadthFirstSearch(startNode) {
        const visited = new Array(this.numberOfNodes + 1).fill(false);
        const nodeQueue = new queue_typescript_1.Queue();
        nodeQueue.enqueue(startNode);
        visited[startNode] = true;
        while (nodeQueue.length > 0) {
            const currentNode = nodeQueue.dequeue();
            process.stdout.write(`${currentNode} `);
            for (const neighbor of this.adjacencyList[currentNode]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    nodeQueue.enqueue(neighbor);
                }
            }
        }
    }
}
exports.BFSGraph = BFSGraph;
