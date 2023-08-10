//
// Created by qays on 8/10/23.
//

#ifndef TASKONE_JUMPINSTRUCTION_H
#define TASKONE_JUMPINSTRUCTION_H
#include "Instruction.h"
#include <sstream>
#include <iostream>

class JumpInstruction : public Instruction {
private:
    int &PC;

public:
    JumpInstruction(int &programCounter) : PC(programCounter) {}

    void execute(std::string instruction) const override {
        std::istringstream iss(instruction);
        std::string opcode;
        int targetAddress;
        iss >> opcode >> targetAddress;

        if (opcode == "jump") {
            PC = targetAddress;
        } else {
            std::cerr << "Incorrect opcode for JumpInstruction!" << std::endl;
        }
    }
};

#endif //TASKONE_JUMPINSTRUCTION_H
