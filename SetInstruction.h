#include "Instruction.h"
#include "RAM.h"
#include <sstream>
#include <iostream>

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
        if (opcode == "set") {
        ram.setValue(addr , val);
        } else {
            std::cerr << "Incorrect opcode for SetInstruction!" << std::endl;
        }
    }
};
