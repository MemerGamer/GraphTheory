import sys
import os

# Add the 'algorithms' folder to the Python path
current_dir = os.path.dirname(os.path.abspath(__file__))
algorithms_dir = os.path.join(current_dir, "algorithms")
sys.path.append(algorithms_dir)

# Add the packages to the Python path
sys.path.append(os.path.join(algorithms_dir, "breadth_first_search"))
sys.path.append(os.path.join(algorithms_dir, "depth_first_search"))
sys.path.append(os.path.join(algorithms_dir, "check_bipartite_algorithm"))
sys.path.append(os.path.join(algorithms_dir, "prufer_encode_decode"))
sys.path.append(os.path.join(algorithms_dir, "kruskals_minimum_spanning_tree"))
sys.path.append(os.path.join(algorithms_dir, "prims_minimum_spanning_tree"))
sys.path.append(os.path.join(algorithms_dir, "dijkstras_shortest_path"))
sys.path.append(os.path.join(algorithms_dir, "bellman-ford"))
sys.path.append(os.path.join(algorithms_dir, "ford_fulkerson_algorithm"))
sys.path.append(os.path.join(algorithms_dir, "floyd_warshall_algorithm"))
