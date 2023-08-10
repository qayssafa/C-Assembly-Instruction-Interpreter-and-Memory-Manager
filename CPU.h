//
// Created by qays on 8/9/23.
//
#include <fstream>
#include <sstream>
#include "ROM.h"
#include "RAM.h"
#include "SetInstruction.h"
#include "AddInstruction.h"
#include "AddiInstruction.h"
#include "PrintInstruction.h"
#include "JumpInstruction.h"

#ifndef TASKONE_CPU_H
#define TASKONE_CPU_H

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

            if (opcode == "set") {
                SetInstruction setInstr(ram);
                setInstr.execute(line);
                PC++;

            } else if(opcode == "add") {
                AddInstruction addInstr(ram);
                addInstr.execute(line);
                PC++;

            } else if(opcode == "addi") {
                AddiInstruction addiInstr(ram);
                addiInstr.execute(line);
                PC++;

            } else if(opcode == "exit") {
                exit(0);

            } else if(opcode == "print") {
                PrintInstruction printInstr(ram);
                printInstr.execute(line);
                PC++;

            } else if(opcode == "jump") {
                JumpInstruction jumpInstr(PC);
                jumpInstr.execute(line);
                // No PC++ here, since the JumpInstruction modifies the PC directly

            } else {
               // std::cerr << "Unknown instruction: " << opcode << std::endl;
                PC++;  // Go to next instruction even if current is unknown
            }
        }
    }




};

#endif //TASKONE_CPU_H
