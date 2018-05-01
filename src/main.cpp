#include <iostream>
#include <algorithm>
#include <vector>
#include "Lexer.h"

int main(int argc, char *argv[]) {
    std::vector<char> v = (argc == 2 ? lexer(argv[1]) : lexer());
    std::for_each(v.begin(), v.end(), putchar);
}
