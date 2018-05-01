#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <vector>
#include <queue>
#include <stdio.h>
#include "Instruction.h"

class Interpreter {
    std::vector<unsigned char> tape;
    int pos = 0;

    void runtime_error(const std::string &message) {
        std::cout << message << '\n';
        exit(1);
    }

    void move(int step) {
        pos += step;
        if (pos < 0)
            runtime_error("Runtime error: Stepped outside of tape");
        if (pos >= tape.size())
            tape.resize(tape.size() * 2);
    }

    void loop(const Instruction &i) {
        auto exec = [this](const Instruction &i){ execute(i); };
        while (tape[pos] != '\0')
            std::for_each(i.insts->begin(), i.insts->end(), exec);
    }

    void print() { putchar(tape[pos]); }
    void read()  { std::cin >> tape[pos];  }

    void execute(const Instruction &i) {
        switch (i.type) {
            case INC:    ++tape[pos]; break;
            case DECR:   --tape[pos]; break;
            case MOVE_L: move(-1);    break;
            case MOVE_R: move(1);     break;
            case LOOP:   loop(i);     break;
            case OUT:    print();     break;
            case IN:     read();      break;
        }
    }

public:
    Interpreter() : tape(1) { }

    void run(std::queue<Instruction> insts) {
        while (!insts.empty()) {
            execute(insts.front());
            insts.pop();
        }
    }
};

#endif /* INTERPRETER_H */
