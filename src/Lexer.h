#ifndef LEXER_H
#define LEXER_H

#include <queue>
#include <fstream>

const std::string allowed_chars = "+-.,<>[]";

std::queue<char> lexer() {
    std::queue<char> tokens;
    char c;
    while((c = getchar_unlocked()) != EOF) {
        if (allowed_chars.find(c) != std::string::npos)
            tokens.emplace(c);
    }
    return tokens;
}

std::queue<char> lexer(std::string file_path) {
    std::ifstream is(file_path);
    std::queue<char> tokens;
    char c;
    while(is.get(c)) {
        if (allowed_chars.find(c) != std::string::npos)
            tokens.emplace(c);
    }
    is.close();
    return tokens;
}

#endif /* LEXER_H */
