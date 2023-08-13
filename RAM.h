
#include "vector"
#include "string"
#include "Memory.h"
#pragma once
class RAM : public Memory{

public:
    RAM(int size):Memory(size){}
    int getValue(int address) const override {
        return std::stoi(data[address]);
    }
    void setValue(int address , int value){
        data[address] = std::to_string(value);
    }
    void setDefultValue(){
        for(int i = 0 ; i < data.size() ; i++){
            data[i] = "0";
        }
    }
};
