#include <iostream>
#include <algorithm>
#include <queue>
#include "Lexer.h"
#include "Parser.h"
#include "BFInterpreter.h"

int main(int argc, char *argv[]) {
    // Filter the input into tokens
    auto tokens = (argc == 2 ? lexer(argv[1]) : lexer());

    // Parse the tokens into instructions
    Parser p(tokens);
    auto insts = p.parse();

    // Run the instructions
    BFInterpreter i;
    i.run(insts);
}
