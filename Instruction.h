
#include "RAM.h"
#pragma once

class Instruction {
public:
    virtual void execute(std::string Instruction) const = 0;
    virtual ~Instruction() = default;
};


