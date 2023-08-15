#include "Instruction.h"
#include "../Memory/RAM.h"
#include <sstream>
#include <iostream>
#pragma once
class SetInstruction : public Instruction {
private:
    RAM &ram;
public:
    SetInstruction(RAM &ram) : ram(ram) {}

    void execute(std::string instruction) const override {
        InstructionParts parts = Instruction::parseInstruction(instruction);

        if (parts.operands.size() != 2) {
            std::cerr << "Invalid number of operands for SET instruction!" << std::endl;
            exit(0);
        }
        ram.setValue(parts.operands[0], parts.operands[1]);
    }
};

