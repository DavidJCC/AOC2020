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


size_t main() {
    const auto contents = read_file("input_day_1.txt");
    std::vector<size_t> numbers;
    std::string line;
    const auto split = split_string(contents, "\n");

    for (const auto number : split) {
        if (!number.empty()) {
            numbers.push_back(std::stoi(number));
        }
    }

    if (auto result = part_1(numbers); result) {
        std::cout << "Result found for day_1 (part 1): " << result << "\n";
    } else {    
        std::cout << "Couldn't find result for day_1 (part 1)\n";
    }


    if (auto result = part_2(numbers); result) {
        std::cout << "Result found for day_1 (part 2): " << result << "\n";
    } else {    
        std::cout << "Couldn't find result for day_1 (part 2)\n";
    }

    return 0;
}
