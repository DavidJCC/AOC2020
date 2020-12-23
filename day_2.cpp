#include <cstdio>
#include <fstream>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <cassert>

#include "util.h"
#include "tests.hpp"

struct Policy {
    size_t min{};
    size_t max{};
    char character{};
    std::string password;
};

bool is_valid_password(const Policy& policy) {
    auto min = policy.min;
    auto max = policy.max;
    char character = policy.character;

    return (policy.password[min] == character || policy.password[max] == character)
        && (!(policy.password[min] == character && policy.password[max] == character));
}


Policy parse_line_to_policy(const std::string& line) {
    Policy result {};

    if (line.empty()) {
        return result;
    }
    
    String_Eater parser(line);
    result.min = std::stoll(parser.eat_to_next_char('-')) - 1;
    parser.eat_chars(1);

    result.max = std::stoll(parser.eat_to_next_char('  ')) - 1;
    parser.eat_chars(1);

    result.character = parser.eat_to_next_char(':')[0];
    parser.eat_chars(1);
    parser.eat_to_next_char(' ', true);

    result.password = parser.str;
    return result;
}


size_t part_1(const std::vector<std::string>& rules) {
    size_t valid_passwords = 0;

    for (const auto& rule : rules) {
        const auto split = split_string(rule, " ");
        if (split.empty()) {
            continue;
        }

        Policy policy = parse_line_to_policy(rule);

        const auto count = std::count(begin(policy.password), end(policy.password), policy.character);
        if (count >= 1 && (count >= policy.min && count <= policy.max)) {
            ++valid_passwords;
        }
    }

    return valid_passwords;
}

size_t part_2(const std::vector<std::string>& rules) {
    size_t valid_passwords = 0;

    for (const auto& rule : rules) {
        Policy policy = parse_line_to_policy(rule);
        if (is_valid_password(policy)) {
            valid_passwords++;
        }
    }

    return valid_passwords;
}

int main() {
    const auto contents = read_file("input/day_2.txt");
    const auto rules = split_string(contents, "\n");

    PRINT_DAY(2, rules);

    return 0;
}





