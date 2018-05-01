#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <queue>
#include "Instruction.h"

/* A recursive descent parser */
class Parser {
private:
    std::queue<char> tokens;

    void parser_error(const std::string &message) {
        std::cout << message << '\n';
        exit(1);
    }

    Instruction loop() {
        std::shared_ptr<std::vector<Instruction>> v(new std::vector<Instruction>);
        tokens.pop(); // pop the '['
        while(tokens.front() != ']') {
            v->emplace_back(inst(tokens.front()));
            if (tokens.empty()) parser_error("Program ended without ending loop");
        }
        // ']' token gets poped in inst
        return { LOOP, v };
    }

    Instruction inst(char c) {
        Instruction i;
        switch (tokens.front()) {
            case '+': i = INC;    break;
            case '-': i = DECR;   break;
            case '.': i = OUT;    break;
            case ',': i = IN;     break;
            case '<': i = MOVE_L; break;
            case '>': i = MOVE_R; break;
            case '[': i = loop(); break;
            case ']': parser_error("']' before a loop start");
            default: parser_error("Parser: Should never get here");
        }
        tokens.pop();
        return i;
    }

public:
    Parser(const std::queue<char> &tokens) : tokens(tokens) {}

    std::queue<Instruction> parse() {
        std::queue<Instruction> insts;
        while(!tokens.empty())
            insts.emplace(inst(tokens.front()));
        return insts;
    }
};

#endif /* PARSER_H */
