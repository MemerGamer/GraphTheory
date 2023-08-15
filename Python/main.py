#!/bin/env python3

import tests

if __name__ == "__main__":
    import sys

    print("GraphTheory Algorithms")
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <input_file_path> <ALGORITHM> <ALGORITHM> ...")
        sys.exit(1)

    input_file_path = sys.argv[1]

    selected_tests = sys.argv[2:]
    tests.tests(input_file_path, selected_tests)
