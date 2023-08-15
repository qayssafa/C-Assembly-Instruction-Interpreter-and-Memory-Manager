

#pragma once
#include "Instruction.h"
#include <sstream>
#include <iostream>

class JumpInstruction : public Instruction {
private:
    int &PC;

public:
    JumpInstruction(int &programCounter) : PC(programCounter) {}

    void execute(std::string instruction) const override {
        InstructionParts parts = Instruction::parseInstruction(instruction);

        if (parts.opcode != "jump" || parts.operands.size() != 1) {
            std::cerr << "Invalid format for JUMP instruction!" << std::endl;
            exit(0);
        } else {
            PC = parts.operands[0] - 1;
        }
    }
};


