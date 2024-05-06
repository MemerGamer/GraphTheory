"use strict";
var __importDefault = (this && this.__importDefault) || function (mod) {
    return (mod && mod.__esModule) ? mod : { "default": mod };
};
Object.defineProperty(exports, "__esModule", { value: true });
const yargs_1 = __importDefault(require("yargs"));
const tests_1 = require("./tests");
const argv = (0, yargs_1.default)(process.argv.slice(2))
    .usage('Usage: $0 <command> [options]')
    .command('test', 'Run a test for a specific algorithm', yargs => {
    return yargs
        .option('algorithm', {
        alias: 'a',
        describe: 'Specify the algorithm to test',
        choices: [
            'bfs',
            'dfs',
            'check_bipartite',
            'prufer',
            'kruskal',
            'prim',
            'dijkstra',
            'bellman_ford',
            'ford_fulkerson',
            'floyd_warshall',
            'articulation_points',
            'bridges',
            'all'
        ],
        demandOption: true
    })
        .option('input-file', {
        alias: 'i',
        describe: 'Path to the input file containing the graph data',
        demandOption: true
    });
}, argv => {
    console.info('GraphTheory Algorithms');
    const algorithm = argv.algorithm;
    const inputFilePath = argv['input-file'];
    switch (algorithm) {
        case 'bfs':
            (0, tests_1.testBreadthFirstSearch)(inputFilePath);
            break;
        case 'dfs':
            (0, tests_1.testDepthFirstSearch)(inputFilePath);
            break;
        // Add cases for other algorithms here
        default:
            console.error(`Algorithm "${algorithm}" not found.`);
            console.info('Available algorithms: bfs, dfs, check_bipartite, prufer, kruskal, prim, dijkstra, bellman_ford, ford_fulkerson, floyd_warshall, articulation_points, bridges, all');
            break;
    }
})
    .demandCommand(1, 'Please specify a command. Use "test" to run a test.').argv;
