#!/bin/env python3

import tests
import sys
import time

if __name__ == "__main__":
    import sys

    print("GraphTheory Algorithms")
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <input_file_path> <ALGORITHM> <ALGORITHM> ...")
        sys.exit(1)

    input_file_path = sys.argv[1]

    selected_tests = sys.argv[2:]
    # Measure the runtime of tests
    start_time = time.time()  # Record the start time
    tests.tests(input_file_path, selected_tests)

    end_time = time.time()  # Record the end time
    elapsed_time = end_time - start_time

    print(f"Tests completed in {elapsed_time:.6f} seconds.")
