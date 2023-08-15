
#include <iostream>
#include "Memory.h"
#pragma once

class ROM : public Memory {
private:
    bool written = false;
public:
    ROM(int size): Memory(size){}

    void storeData(const std::vector<std::string>& instructions) {


        if(!written) {
            if(data.size() < instructions.size()) {
            std::cout << "Warning: ROM size is smaller than the number of instructions" << std::endl;
            exit(0);
            }
            for(int i = 0; i < instructions.size() && i < data.size(); i++) {
                data[i] = instructions[i];
            }

            written = true;
        } else {
            std::cout << "Data already stored" << std::endl;
        }
    }





};
