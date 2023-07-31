#include <iostream>
#include <utility>
#include "tests.h"

void tests(string input_file_path){
    test_breadth_first_search(std::move(input_file_path));
    test_depth_first_search(std::move(input_file_path));
}
int main(int argc, char** argv) {
    std::cout << "GraphTheory Algorithms" << std::endl;
    if (argc != 2) {
        cout << "Usage: ./"<<argv[0]<<" <input_file_path>\n";
        return 1;
    }
    string input_file_path = argv[1];
    tests(input_file_path);
    return 0;
}
