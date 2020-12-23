#pragma once

#include <string>
#include <fstream>
#include <vector>

struct String_Eater {
    String_Eater(const std::string& str_)
        : str(str_)
        , original(str_)
        , max_size(str.size())
    {}

    std::string original;
    std::string str;

    size_t max_size{};

    std::string eat_chars(const size_t count) {
        std::string result = str.substr(0, count);
        str = str.substr(count, max_size);
        return result;
    }

    std::string eat_to_next_char(const char character, bool include_delim = false) {
        auto pos = str.find_first_of(character);
        if (include_delim) {
            ++pos;
        }

        return eat_chars(pos);
    }
};

inline std::string read_file(const std::string& path) {
    std::ifstream t(path);
    std::string str((std::istreambuf_iterator<char>(t)),
                     std::istreambuf_iterator<char>());

    return str;
}

/**
 * Split a string in to a delimited list.
 *
 * @param str the string value to split.
 * @param delimiter the delimiter value.
 * @return a list of split strings.
 */
using Split_String = std::vector<std::string>;
static auto split_string(const std::string& str, const std::string& delimiter) {
	Split_String result;

	if (!str.empty()) {
		std::size_t last_pos = 0;

		std::size_t pos = str.find_first_of(delimiter, last_pos);
		while (pos != std::string::npos) {
			std::string token = str.substr(last_pos, pos - last_pos);
			if (!token.empty()) {
				result.push_back(token);
			}

			last_pos = pos + 1;
			pos = str.find_first_of(delimiter, last_pos);
		}

		result.push_back(str.substr(last_pos));
	}

	return result;
}

/**
 * Wrapper around strcmp to return if two strings are the same.
 *
 * @param str0 first string.
 * @param str1 second string.
 * @return are the two strings the same?
 */
inline bool string_compare(const char* str0, const char* str1) { return strcmp(str0, str1) == 0; }

#define PRINT_DAY(DAY, DAY_ARG)\
    std::cout << "Day " << DAY << ":\n";\
    std::cout << "    Part 1:       " << part_1(DAY_ARG) << "\n";\
    std::cout << "    Part 2:       " << part_2(DAY_ARG) << "\n";




