//
// Created by qays on 8/9/23.
//
#include "vector"
#include "string"
#ifndef TASKONE_MEMORY_H
#define TASKONE_MEMORY_H
class Memory {
protected:
    std::vector<std::string > data;
public:
    Memory(int size):data(size) {}
    virtual int getValue(int address) const = 0;
    virtual ~Memory() {}
};


#endif //TASKONE_MEMORY_H
