#include "Instruction.h"
#include "RAM.h"
#include <sstream>
#include <iostream>
#pragma once
class SetInstruction : public Instruction {
private:
    RAM &ram;
public:
    SetInstruction(RAM &ram) : ram(ram) {}
    void execute(std::string instruction) const override {
        std::istringstream iss(instruction);
        std::string opcode;
        int addr, val;
        iss >> opcode >> addr >> val;

        if (opcode != "set" || !iss.eof() || iss.fail()) {
            std::cerr << "Invalid format for set instruction!" << std::endl;
            exit(0);
        }else{
            ram.setValue(addr , val);
        }

    }
};
