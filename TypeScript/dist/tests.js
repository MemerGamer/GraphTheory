"use strict";
var __createBinding = (this && this.__createBinding) || (Object.create ? (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    var desc = Object.getOwnPropertyDescriptor(m, k);
    if (!desc || ("get" in desc ? !m.__esModule : desc.writable || desc.configurable)) {
      desc = { enumerable: true, get: function() { return m[k]; } };
    }
    Object.defineProperty(o, k2, desc);
}) : (function(o, m, k, k2) {
    if (k2 === undefined) k2 = k;
    o[k2] = m[k];
}));
var __setModuleDefault = (this && this.__setModuleDefault) || (Object.create ? (function(o, v) {
    Object.defineProperty(o, "default", { enumerable: true, value: v });
}) : function(o, v) {
    o["default"] = v;
});
var __importStar = (this && this.__importStar) || function (mod) {
    if (mod && mod.__esModule) return mod;
    var result = {};
    if (mod != null) for (var k in mod) if (k !== "default" && Object.prototype.hasOwnProperty.call(mod, k)) __createBinding(result, mod, k);
    __setModuleDefault(result, mod);
    return result;
};
Object.defineProperty(exports, "__esModule", { value: true });
exports.testDepthFirstSearch = exports.testBreadthFirstSearch = void 0;
const fs = __importStar(require("node:fs"));
const breadth_first_search_1 = require("./breadth-first-search/breadth-first-search");
const depth_first_search_1 = require("./depth-first-search/depth-first-search");
/**
 * Function to test the Breadth-First Search (BFS) algorithm.
 * @param inputFilePath The path to the input file containing the graph data.
 */
function testBreadthFirstSearch(inputFilePath) {
    // Benchmark the execution time of the BFS algorithm
    const startTime = Date.now();
    // Read the number of nodes and edges from the input file
    let numberOfNodes = 0;
    let numberOfEdges = 0;
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
        const bfsGraph = new breadth_first_search_1.BFSGraph(numberOfNodes + 1);
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
    });
    const endTime = Date.now();
    const elapsedTimeInMs = endTime - startTime; // / 1_000_000.0;
    console.info(`Elapsed time: ${elapsedTimeInMs.toFixed(6)} seconds`);
}
exports.testBreadthFirstSearch = testBreadthFirstSearch;
/**
 * Function to test the Depth-First Search (DFS) algorithm.
 * @param inputFilePath The path to the input file containing the graph data.
 */
function testDepthFirstSearch(inputFilePath) {
    // Benchmark the execution time of the DFS algorithm
    const startTime = Date.now();
    // Read the number of nodes and edges from the input file
    let numberOfNodes = 0;
    let numberOfEdges = 0;
    fs.readFile(inputFilePath, 'utf8', (err, data) => {
        if (err) {
            console.error(err);
            return;
        }
        const lines = data.split('\n');
        [numberOfNodes, numberOfEdges] = lines[0].split(' ').map(Number);
        // console.info(`Number of nodes: ${numberOfNodes}`);
        // console.info(`Number of edges: ${numberOfEdges}`);
        // console.info(`Graph data:`);
        // for (let i = 1; i < lines.length; i++) {
        //   console.info(lines[i]);
        // }
        // Create an instance of the DFSGraph class
        const dfsGraph = new depth_first_search_1.DFSGraph(numberOfNodes + 1);
        // Parse and add edges to the graph
        for (let i = 1; i <= numberOfEdges; i++) {
            const [firstNode, secondNode] = lines[i].split(' ').map(Number);
            dfsGraph.addEdgeNonDirected(firstNode, secondNode);
        }
        // Choose a starting node for DFS (e.g., node 1)
        const startNode = 1;
        // Perform DFS starting from the chosen node
        console.log(`DFS traversal starting from node ${startNode}:`);
        dfsGraph.depthFirstSearch(startNode);
    });
    const endTime = Date.now();
    const elapsedTimeInMs = endTime - startTime; // / 1_000_000.0;
    console.info(`Elapsed time: ${elapsedTimeInMs.toFixed(6)} seconds`);
}
exports.testDepthFirstSearch = testDepthFirstSearch;
