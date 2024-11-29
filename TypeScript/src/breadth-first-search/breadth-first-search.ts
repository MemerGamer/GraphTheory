import { Queue } from 'queue-typescript'; // Import a queue library for TypeScript

/**
 * Represents a class for performing Breadth-First Search (BFS) on a graph.
 */
export class BFSGraph {
  private numberOfNodes: number; // The number of nodes in the graph
  private adjacencyList: number[][]; // Adjacency list representing the graph

  /**
   * Constructor for the BFSGraph class.
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
   * Perform Breadth-First Search (BFS) starting from a specified node.
   * @param startNode The starting node for BFS traversal.
   */
  breadthFirstSearch(startNode: number): void {
    const visited: boolean[] = new Array<boolean>(this.numberOfNodes + 1).fill(false);
    const nodeQueue: Queue<number> = new Queue<number>();
    nodeQueue.enqueue(startNode);
    visited[startNode] = true;

    const traversedNodes: number[] = [];

    while (nodeQueue.length > 0) {
      const currentNode: number = nodeQueue.dequeue() as number;
      traversedNodes.push(currentNode);
      for (const neighbor of this.adjacencyList[currentNode]) {
        if (!visited[neighbor]) {
          visited[neighbor] = true;
          nodeQueue.enqueue(neighbor);
        }
      }
    }

    console.log(traversedNodes.join(' '));
  }
}
