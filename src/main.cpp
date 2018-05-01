#include <iostream>
#include <algorithm>
#include <queue>
#include "Lexer.h"
#include "Parser.h"

int main(int argc, char *argv[]) {
    std::queue<char> v = (argc == 2 ? lexer(argv[1]) : lexer());
    Parser p(v);
    auto q = p.parse();
    while (!q.empty()) {
        std::cout << q.front();
        q.pop();
    }
}
