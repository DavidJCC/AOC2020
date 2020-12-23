#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

#include "util.h"

static constexpr size_t MAGIC_NUMBER = 2020;

size_t part_1(const std::vector<size_t> & numbers) {
    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = i + 1; j < numbers.size(); ++j) {
            if (numbers[i] + numbers[j] == MAGIC_NUMBER) {
                return numbers[i] * numbers[j];
            }
        }
    }

    return 0;
}

size_t part_2(const std::vector<size_t> & numbers) {
    for (size_t i = 0; i < numbers.size(); ++i) {
        for (size_t j = i + 1; j < numbers.size(); ++j) {
            for (size_t k = j + 1; k < numbers.size(); ++k) {
                if (numbers[i] + numbers[j] + numbers[k] == MAGIC_NUMBER) {
                    return numbers[i] * numbers[j] * numbers[k];
                }
            }
        }
    }

    return 0;
}


int main() {
    const auto contents = read_file("input/day_1.txt");
    std::vector<size_t> numbers;
    std::string line;
    const auto split = split_string(contents, "\n");

    for (const auto number : split) {
        if (!number.empty()) {
            numbers.push_back(std::stoi(number));
        }
    }

    PRINT_DAY(1, numbers);

    return 0;
}
