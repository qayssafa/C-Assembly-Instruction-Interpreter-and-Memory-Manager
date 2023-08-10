//
// Created by qays on 8/9/23.
//
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

        rom.storeData(instructions);

    }


    std::string getFirstWord(const std::string& str) {
        std::istringstream iss(str);
        std::string firstWord;
        iss >> firstWord;
        return firstWord;
    }

    /*void decodeAndExecute() {
        const auto& rawInstructions = rom.getData();

        for (const auto& line : rawInstructions) {
            std::string opcode = getFirstWord(line);

            if (opcode == "set") {
                SetInstruction setInstr(ram);
                setInstr.execute(line);
                PC++;

            } else if(opcode == "add"){
                AddInstruction addInstr(ram);
                addInstr.execute(line);
                PC++;

            } else if(opcode == "addi"){
                AddiInstruction addiInstr(ram);
                addiInstr.execute(line);
                PC++;

            }else if(opcode == "exit"){
                PC++;
                exit(0);


            }else if(opcode == "print"){
                PrintInstruction printInsrt(ram);
                printInsrt.execute(line);
                PC++;

            }else if(opcode == "jump"){
                JumpInstruction jumpInstr(PC);
                jumpInstr.execute(line);

            }

        }
    }*/

    void decodeAndExecute() {
        const auto& rawInstructions = rom.getData();

        while (PC < rawInstructions.size()) {
            std::string line = rawInstructions[PC];
            std::string opcode = getFirstWord(line);

            std::unique_ptr<Instruction> instr;  // Define a unique_ptr for the Instruction base class

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

            if (instr) {  // If we successfully created an instruction object
                instr->execute(line);

                // Only increment PC if the instruction wasn't "jump"
                if (opcode != "jump") {
                    PC++;
                }
            } else {
                // If the instruction was unknown
                PC++;
            }
        }
    }





};

