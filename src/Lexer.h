#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <fstream>
#include <string>

const std::string allowed_chars = "+-.,<>[]";

std::vector<char> lexer() {
    std::vector<char> tokens;
    char c;
    while((c = getchar_unlocked()) != EOF) {
        if (allowed_chars.find(c) != std::string::npos)
            tokens.emplace_back(c);
    }
    return tokens;
}

std::vector<char> lexer(std::string file_path) {
    std::ifstream is(file_path);
    std::vector<char> tokens;
    char c;
    while(is.get(c)) {
        if (allowed_chars.find(c) != std::string::npos)
            tokens.emplace_back(c);
    }
    is.close();
    return tokens;

}

#endif /* LEXER_H */
