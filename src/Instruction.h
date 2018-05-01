#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <queue>

enum InstructionType {INC, DECR, LOOP, OUT, IN, MOVE_L, MOVE_R};

struct Instruction {
    InstructionType type;
    std::unique_ptr<std::vector<Instruction>> insts;

    Instruction(InstructionType type, std::unique_ptr< std::vector<Instruction> > v = nullptr) : type(type), insts(std::move(v)) {}

    // Yay, c++!
    Instruction() = default;
    Instruction(Instruction &rhs) = default;
    Instruction(Instruction &&rhs) = default;
    Instruction& operator=(Instruction &i) = default;
    Instruction& operator=(Instruction &&i) = default;
    ~Instruction() = default;
};

std::ostream& operator<<(std::ostream &os, const Instruction &i) {
    switch(i.type) {
        case INC:    return os << "INC\n";
        case DECR:   return os << "DECR\n";
        case OUT:    return os << "OUT\n";
        case IN:     return os << "IN\n";
        case MOVE_L: return os << "MOVE_L\n";
        case MOVE_R: return os << "MOVE_R\n";
        case LOOP:
            os << "LOOP START\n";
            std::for_each(i.insts->begin(), i.insts->end(), [&os](Instruction &i){ os << "  " << i; });
            os << "LOOP END\n";
    }
    return os;
}

#endif /* INSTRUCTION_H */
