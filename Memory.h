
#include "vector"
#include "string"
#pragma once
class Memory {
protected:
    std::vector<std::string > data;
public:
    Memory(int size):data(size) {}
    virtual int getValue(int address) const = 0;
    virtual ~Memory() {}
};


