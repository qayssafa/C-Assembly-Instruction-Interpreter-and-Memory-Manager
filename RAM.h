//
// Created by qays on 8/9/23.
//

#include "vector"
#include "string"
#include "Memory.h"
#ifndef TASKONE_RAM_H
#define TASKONE_RAM_H
class RAM : public Memory{

public:
    RAM(int size):Memory(size){}
    int getValue(int address) const override {
        return std::stoi(data[address]);
    }
    void setValue(int address , int value){
        data[address] = std::to_string(value);
    }
};
#endif //TASKONE_RAM_H
