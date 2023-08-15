
#include "../Memory/RAM.h"
#pragma once


class Instruction {
public:
    struct InstructionParts {
        std::string opcode;
        std::vector<int> operands;
    };

    virtual void execute(std::string Instruction) const = 0;
    virtual ~Instruction() = default;

protected:
    static InstructionParts parseInstruction(const std::string& instruction) {
        InstructionParts parts;
        std::istringstream iss(instruction);
        iss >> parts.opcode;

        int operand;
        while(iss >> operand) {
            parts.operands.push_back(operand);
        }

        if (!iss.fail()) {
            std::cerr << "Error parsing instruction!" << std::endl;
            exit(0);
        }
        return parts;
    }
};



