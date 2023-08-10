//
// Created by qays on 8/9/23.
//
#include <iostream>
#include "Memory.h"
#pragma once

class ROM : public Memory {
private:
    bool written = false;
public:
    ROM(int size): Memory(size){}
    int getValue(int address) const override {
        return std::stoi(data[address]);
    }
    const std::vector<std::string>& getData() const {
        return data;
    }
    void storeData(const std::vector<std::string>& instructions) {
        if(!written) {
            for(int i = 0; i < instructions.size() && i < data.size(); i++) {
                data[i] = instructions[i];
            }
            std::cout << "Data stored" << std::endl;
            written = true;
        } else {
            std::cout << "Data already stored" << std::endl;
        }
    }

};
