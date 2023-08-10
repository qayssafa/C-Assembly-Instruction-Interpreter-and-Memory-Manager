//
// Created by qays on 8/10/23.
//

#pragma once
#include "Instruction.h"
#include "RAM.h"
#include <sstream>
#include <iostream>

class AddiInstruction : public Instruction {
private:
    RAM &ram;

public:
    AddiInstruction(RAM &ram) : ram(ram) {}

    void execute(std::string instruction) const override {
        std::istringstream iss(instruction);
        std::string opcode;
        int addr1, immediateValue, addr2;
        iss >> opcode >> addr1 >> immediateValue >> addr2;

        if (opcode != "addi" || !iss.eof() || iss.fail()) {
            std::cerr << "Invalid format for ADDi instruction!" << std::endl;
            exit(0);
        }else{
            int sum = ram.getValue(addr1) + immediateValue;
            ram.setValue(addr2, sum);
        }

    }
};

