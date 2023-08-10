//
// Created by qays on 8/10/23.
//
#include "RAM.h"
#pragma once
class Instruction {
public:
    virtual void execute(std::string Instruction) const = 0;
    virtual ~Instruction() = default;
};


