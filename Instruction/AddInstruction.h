
#pragma once
#include "Instruction.h"
#include "../Memory/RAM.h"
#include <sstream>
#include <iostream>

class AddInstruction : public Instruction {
private:
    RAM &ram;

public:
    AddInstruction(RAM &ram) : ram(ram) {}

    void execute(std::string instruction) const override {
        InstructionParts parts = Instruction::parseInstruction(instruction);

        if (parts.operands.size() != 3) {
            std::cerr << "Invalid format for ADD instruction!" << std::endl;
            exit(0);
        } else {
            int sum = ram.getValue(parts.operands[0]) + ram.getValue(parts.operands[1]);
            ram.setValue(parts.operands[2], sum);
        }
    }
};
