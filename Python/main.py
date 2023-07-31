import tests

if __name__ == "__main__":
    import sys

    print("GraphTheory Algorithms")
    if len(sys.argv) != 2:
        print(f"Usage: {sys.argv[0]} <input_file_path>")
        sys.exit(1)

    input_file_path = sys.argv[1]
    # test_breadth_first_search(input_file_path)
    tests.tests(input_file_path)
