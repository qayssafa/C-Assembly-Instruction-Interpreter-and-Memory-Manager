//
// Created by qays on 8/10/23.
//

#pragma once
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

        if (opcode != "jump" || !iss.eof() || iss.fail()) {
            std::cerr << "Invalid format for jump instruction!" << std::endl;
            exit(0);
        }else{
            PC = targetAddress;
        }

       /* if (opcode == "jump") {
            PC = targetAddress;
        } else {
            std::cerr << "Incorrect opcode for JumpInstruction!" << std::endl;
        }*/
    }
};

