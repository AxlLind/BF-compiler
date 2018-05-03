#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <iostream>
#include <queue>

enum InstructionType {INC, DECR, LOOP, OUT, IN, MOVE_L, MOVE_R};

struct Instruction {
    InstructionType type;
    std::shared_ptr<std::vector<Instruction>> insts;

    Instruction() = default;
    Instruction(const Instruction&) = default;
    Instruction(InstructionType type, std::shared_ptr< std::vector<Instruction> > v = nullptr) : type(type), insts(v) { }
};

#endif /* INSTRUCTION_H */
