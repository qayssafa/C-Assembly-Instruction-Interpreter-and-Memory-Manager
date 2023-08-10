//
// Created by qays on 8/10/23.
//
#include "RAM.h"
#
#ifndef TASKONE_INSTRUCTION_H
#define TASKONE_INSTRUCTION_H
class Instruction {
public:
    virtual void execute(std::string Instruction) const = 0;
    virtual ~Instruction() = default;
};

#endif //TASKONE_INSTRUCTION_H
