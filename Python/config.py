import sys
import os

# Add the 'algorithms' folder to the Python path
current_dir = os.path.dirname(os.path.abspath(__file__))
algorithms_dir = os.path.join(current_dir, "algorithms")
sys.path.append(algorithms_dir)

# Add the 'algorithms.breadth_first_search' package to the Python path
sys.path.append(os.path.join(algorithms_dir, "breadth_first_search"))
sys.path.append(os.path.join(algorithms_dir, "depth_first_search"))
