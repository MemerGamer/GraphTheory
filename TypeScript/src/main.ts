import yargs from 'yargs';
import { testBreadthFirstSearch, testDepthFirstSearch } from './tests';

const argv = yargs(process.argv.slice(2))
  .usage('Usage: $0 <command> [options]')
  .command(
    'test',
    'Run a test for a specific algorithm',
    yargs => {
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
    },
    argv => {
      console.info('GraphTheory Algorithms');
      const algorithm = argv.algorithm as string;
      const inputFilePath = argv['input-file'] as string;

      switch (algorithm) {
        case 'bfs':
          testBreadthFirstSearch(inputFilePath);
          break;
        case 'dfs':
          testDepthFirstSearch(inputFilePath);
          break;
        // Add cases for other algorithms here
        default:
          console.error(`Algorithm "${algorithm}" not found.`);
          console.info(
            'Available algorithms: bfs, dfs, check_bipartite, prufer, kruskal, prim, dijkstra, bellman_ford, ford_fulkerson, floyd_warshall, articulation_points, bridges, all'
          );
          break;
      }
    }
  )
  .demandCommand(1, 'Please specify a command. Use "test" to run a test.').argv;
