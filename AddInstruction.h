//
// Created by qays on 8/10/23.
//

#pragma once
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

        if (opcode != "add" || !iss.eof() || iss.fail()) {
            std::cerr << "Invalid format for ADD instruction!" << std::endl;
            exit(0);
        }else{
            int sum = ram.getValue(addr1) + ram.getValue(addr2);
            ram.setValue(addr3, sum);
        }

    }
};

