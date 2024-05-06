import { Queue } from 'queue-typescript'; // Import a queue library for TypeScript

/**
 * Represents a class for performing Depth-First Search (DFS) on a graph.
 */
export class DFSGraph {
  private numberOfNodes: number; // The number of nodes in the graph
  private adjacencyList: number[][]; // Adjacency list representing the graph

  /**
   * Constructor for the DFSGraph class.
   * @param numberOfNodes The number of nodes in the graph.
   */
  constructor(numberOfNodes: number) {
    this.numberOfNodes = numberOfNodes;
    this.adjacencyList = new Array<number[]>(numberOfNodes + 1).fill([]);
  }

  /**
   * Add an undirected edge between two nodes in the graph.
   * @param firstNode The first node.
   * @param secondNode The second node.
   */
  addEdgeNonDirected(firstNode: number, secondNode: number): void {
    this.adjacencyList[firstNode].push(secondNode);
    this.adjacencyList[secondNode].push(firstNode);
  }

  /**
   * Add a directed edge from the first node to the second node in the graph.
   * @param firstNode The source node.
   * @param secondNode The target node.
   */
  addEdgeDirected(firstNode: number, secondNode: number): void {
    this.adjacencyList[firstNode].push(secondNode);
  }

  /**
   * Perform Depth-First Search (DFS) starting from a specified node.
   * @param startNode The starting node for DFS traversal.
   */
  depthFirstSearch(startNode: number): void {
    const visited: boolean[] = new Array<boolean>(this.numberOfNodes + 1).fill(false);
    this.dfsHelper(startNode, visited);
    console.log();
  }

  private dfsHelper(currentNode: number, visited: boolean[]): void {
    visited[currentNode] = true;
    process.stdout.write(`${currentNode} `);

    for (const neighbor of this.adjacencyList[currentNode]) {
      if (!visited[neighbor]) {
        this.dfsHelper(neighbor, visited);
      }
    }
  }
}
