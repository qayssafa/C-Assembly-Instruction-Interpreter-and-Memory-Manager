//
// Created by qays on 8/10/23.
//

#ifndef TASKONE_PRINTINSTRUCTION_H
#define TASKONE_PRINTINSTRUCTION_H
#include "Instruction.h"
#include "RAM.h"
#include <sstream>
#include <iostream>

class PrintInstruction : public Instruction {
private:
    RAM &ram;

public:
    PrintInstruction(RAM &ramInstance) : ram(ramInstance) {}

    void execute(std::string instruction) const override {
        std::istringstream iss(instruction);
        std::string opcode;
        int addr;
        iss >> opcode >> addr;

        if (opcode == "print") {
            int value = ram.getValue(addr);
            std::cout << "Value at address " << addr << ": " << value << std::endl;
        } else {
            std::cerr << "Incorrect opcode for PrintInstruction!" << std::endl;
        }
    }
};

#endif //TASKONE_PRINTINSTRUCTION_H
