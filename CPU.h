
#include <fstream>
#include <sstream>
#include <memory>
#include "ROM.h"
#include "RAM.h"
#include "SetInstruction.h"
#include "AddInstruction.h"
#include "AddiInstruction.h"
#include "PrintInstruction.h"
#include "JumpInstruction.h"

#pragma once

class CPU{
private:
    int PC = 0;
    ROM &rom;
    RAM &ram;

public:
    CPU(ROM &rom , RAM &ram) : rom(rom) , ram(ram){}
    std::vector<std::string> instructions;

    void start(const std::string& filename){
        ReadDataFromTextFile(filename);
        rom.storeData(instructions);
        decodeAndExecute();
    }

    void ReadDataFromTextFile (std::string filename){
        std::ifstream inputFile(filename);

        if (!inputFile) {
            std::cout << "Failed to open the instructions file." << std::endl;
        }

        std::string line;
        while (getline(inputFile, line)) {
            instructions.push_back(line);
        }

        inputFile.close();
        
    }


    std::string getFirstWord(const std::string& str) {
        std::istringstream iss(str);
        std::string firstWord;
        iss >> firstWord;
        return firstWord;
    }

    void decodeAndExecute() {
        ram.setDefultValue();
        const auto& rawInstructions = rom.getData();

        while (PC < rawInstructions.size()) {
            std::string line = rawInstructions[PC];
            std::string opcode = getFirstWord(line);

            std::unique_ptr<Instruction> instr;

            if (opcode == "set") {
                instr = std::make_unique<SetInstruction>(ram);

            } else if(opcode == "add") {
                instr = std::make_unique<AddInstruction>(ram);

            } else if(opcode == "addi") {
                instr = std::make_unique<AddiInstruction>(ram);

            } else if(opcode == "exit") {
                exit(0);

            } else if(opcode == "print") {
                instr = std::make_unique<PrintInstruction>(ram);

            } else if(opcode == "jump") {
                instr = std::make_unique<JumpInstruction>(PC);

            }

            if (instr) {
                instr->execute(line);

                if (opcode != "jump") {
                    PC++;
                }
            } else {
                std::cerr << "Invalid opcode!" << std::endl;
                exit(0);
            }
        }
    }
};

