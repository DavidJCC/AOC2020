#include <iostream>

#include "util.h"
#include "tests.hpp"

size_t check_slope(const Split_String& contents, size_t right, size_t down) {
    const auto width = contents[0].size();
    const auto height = contents.size();

    size_t x = right;
    size_t y = down;

    size_t count = 0;

    while (y < height) {
        if (contents[y][x] == '#') {
            count++;
        } 

        x += right;
        x = x % width;

        y += down;
    }

    return count;
}

size_t part_1(const Split_String& contents) {
    return check_slope(contents, 3, 1);
}

size_t part_2(const Split_String& contents) {
    return 
        check_slope(contents, 1, 1)
        * check_slope(contents, 3, 1)
        * check_slope(contents, 5, 1)
        * check_slope(contents, 7, 1)
        * check_slope(contents, 1, 2);
}

int main(int argc, char* argv[]) {
    std::string path = "sample.txt";

    if (argc > 1 && argv[1]) {
        path = argv[1];
    }

    const auto contents = split_string(read_file(path), "\n");

    PRINT_DAY(3, contents);

    return 0;
}





