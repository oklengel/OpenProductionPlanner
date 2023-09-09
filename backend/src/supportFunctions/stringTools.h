
#pragma once

#include <string>

inline std::string removeQuotes(const std::string& input) {
    if (input.size() >= 2 && input.front() == '"' && input.back() == '"') {
        return input.substr(1, input.size() - 2);
    } else {
        return input;
    }
}