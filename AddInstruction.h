//
// Created by qays on 8/10/23.
//

#ifndef TASKONE_ADDINSTRUCTION_H
#define TASKONE_ADDINSTRUCTION_H
#include "Instruction.h"
#include "RAM.h"
#include <sstream>
#include <iostream>

class AddInstruction : public Instruction {
private:
    RAM &ram;

public:
    AddInstruction(RAM &ram) : ram(ram) {}

    void execute(std::string instruction) const override {
        std::istringstream iss(instruction);
        std::string opcode;
        int addr1, addr2, addr3;
        iss >> opcode >> addr1 >> addr2 >> addr3;

        if (opcode == "add") {
            int sum = ram.getValue(addr1) + ram.getValue(addr2);
            ram.setValue(addr3, sum);
        } else {
            std::cerr << "Incorrect opcode for AddInstruction!" << std::endl;
        }
    }
};

#endif //TASKONE_ADDINSTRUCTION_H
