
#pragma once
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

        if (opcode != "print" || !iss.eof() || iss.fail()) {
            std::cerr << "Invalid format for print instruction!" << std::endl;
            exit(0);
        }else{
            int value = ram.getValue(addr);
            std::cout << "Value at address " << addr << ": " << value << std::endl;
        }

      /*  if (opcode == "print") {
            int value = ram.getValue(addr);
            std::cout << "Value at address " << addr << ": " << value << std::endl;
        } else {
            std::cerr << "Incorrect opcode for PrintInstruction!" << std::endl;
        }*/
    }
};

