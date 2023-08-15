
#pragma once
#include "Instruction.h"
#include "../Memory/RAM.h"
#include <sstream>
#include <iostream>

class AddiInstruction : public Instruction {
private:
    RAM &ram;

public:
    AddiInstruction(RAM &ram) : ram(ram) {}


    void execute(std::string instruction) const override {
        InstructionParts parts = Instruction::parseInstruction(instruction);

        if (parts.operands.size() != 3) {
            std::cerr << "Invalid number of operands for ADDi instruction!" << std::endl;
            exit(0);
        }
        int sum = ram.getValue(parts.operands[0]) + parts.operands[1];
        ram.setValue(parts.operands[2], sum);
    }
};

