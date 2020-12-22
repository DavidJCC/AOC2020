#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include "util.h"

size_t part_1(const std::vector<std::string>& rules) {
    size_t valid_passwords = 0;

    for (const auto& rule : rules) {
        const auto split = split_string(rule, " ");
        if (split.empty()) {
            continue;
        }

        const auto range_string = split_string(split[0], "-");
        const auto min = std::stoi(range_string[0]);
        const auto max = std::stoi(range_string[1]);

        const auto character = split_string(split[1], ":")[0];
        const auto password = split[2];

        const auto count = std::count(begin(password), end(password), character[0]);
        if (count >= 1 && (count >= min && count <= max)) {
            ++valid_passwords;
        }
    }

    return valid_passwords;
}

size_t part_2(const std::vector<std::string>& rules) {
    size_t valid_passwords = 0;

    for (const auto& rule : rules) {
        const auto split = split_string(rule, " ");
        if (split.empty()) {
            continue;
        }

        const auto range_string = split_string(split[0], "-");
        const auto min = std::stoi(range_string[0]) - 1;
        const auto max = std::stoi(range_string[1]) - 1;

        const auto character = split_string(split[1], ":")[0];
        const auto password = split[2];

        if (password[min] == character[0] || password[max] == character[0]) {
            if (!(password[min] == character[0] && password[max] == character[0])) {
                ++valid_passwords;
            }
        }
    }

    return valid_passwords;
}


int main() {
    const auto contents = read_file("input_day_2.txt");
    const auto rules = split_string(contents, "\n");

    if (const auto result = part_1(rules); result) {
        std::cout << "Result found for day_2 (part 1): " << result << "\n";
    } else {    
        std::cout << "Couldn't find result for day_2 (part 1)\n";
    }

    if (const auto result = part_2(rules); result) {
        std::cout << "Result found for day_2 (part 2): " << result << "\n";
    } else {    
        std::cout << "Couldn't find result for day_2 (part 2)\n";
    }


    return 0;
}
