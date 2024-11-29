import { BFSGraph } from './breadth-first-search/breadth-first-search';
import * as fs from 'node:fs';

/**
 * Function to test the Breadth-First Search (BFS) algorithm.
 * @param inputFilePath The path to the input file containing the graph data.
 */
export function testBreadthFirstSearch(inputFilePath: string): void {
  // Benchmark the execution time of the BFS algorithm
  const startTime = Date.now();

  // Read the number of nodes and edges from the input file
  let numberOfNodes: number = 0;
  let numberOfEdges: number = 0;

  fs.readFile(inputFilePath, 'utf8', (err, data) => {
    if (err) {
      console.error(err);
      return;
    }

    // console.info(`Reading input file: ${inputFilePath}`);

    const lines = data.split('\n');
    // console.info(`File contents (lines): ${lines}`);
    [numberOfNodes, numberOfEdges] = lines[0].split(' ').map(Number);

    // Create an instance of the BFSGraph class
    const bfsGraph = new BFSGraph(numberOfNodes + 1);

    // Parse and add edges to the graph
    for (let i = 1; i < lines.length; i++) {
      const edgeData = lines[i].split(' ');
      if (edgeData.length === 2) {
        const firstNode = parseInt(edgeData[0]);
        const secondNode = parseInt(edgeData[1]);
        // console.info(`Adding edge: ${firstNode} ${secondNode}`);
        bfsGraph.addEdgeNonDirected(firstNode, secondNode);
      }
    }

    // Choose a starting node for BFS (e.g., node 1)
    const startNode = 1;

    // Perform BFS starting from the chosen node
    console.log(`Breadth-First Search from node ${startNode}:`);
    bfsGraph.breadthFirstSearch(startNode);

    const endTime = Date.now();
    const elapsedTimeInMs = endTime - startTime; // / 1_000_000.0;
    console.info(`Elapsed time: ${(elapsedTimeInMs / 1000).toFixed(6)} seconds`);
  });
}
