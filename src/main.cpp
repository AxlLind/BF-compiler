#include <iostream>
#include <algorithm>
#include <queue>
#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"

int main(int argc, char *argv[]) {
    auto tokens = (argc == 2 ? lexer(argv[1]) : lexer());

    Parser p(tokens);
    auto insts = p.parse();

    Interpreter i;
    i.run(insts);
}
