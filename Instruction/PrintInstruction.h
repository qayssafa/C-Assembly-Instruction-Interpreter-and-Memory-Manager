
#pragma once
#include "Instruction.h"
#include "../Memory/RAM.h"
#include <sstream>
#include <iostream>

class PrintInstruction : public Instruction {
private:
    RAM &ram;

public:
    PrintInstruction(RAM &ramInstance) : ram(ramInstance) {}


    void execute(std::string instruction) const override {
        InstructionParts parts = Instruction::parseInstruction(instruction);

        if (parts.operands.size() != 1) {
            std::cerr << "Invalid format for PRINT instruction!" << std::endl;
            exit(0);
        } else {
            int value = ram.getValue(parts.operands[0]);
            std::cout << "Value at address " << parts.operands[0] << ": " << value << std::endl;
        }
    }
};

