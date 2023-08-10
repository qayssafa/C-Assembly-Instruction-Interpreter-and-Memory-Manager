#include <iostream>
#include "Memory.h"
#include "RAM.h"
#include "ROM.h"
#include "CPU.h"
#include <iostream>
#include <fstream>


int main() {
    RAM ram(255);
    ROM rom(15);
    CPU cpu(rom , ram);

    ram.setValue(1,5);
    ram.setValue(2 , 5);
    ram.setValue(3 , 5);



    /*int i = ram.getValue(11);
    std::cout<<i<<std::endl;
     i = ram.getValue(10);
    std::cout<<i<<std::endl;*/

   /* std::vector<std::string> instructions= {
            "set 10 100",
            "add 10 11 12",
            "addi 10 5 13",
            "print 12",
            "exit"
    };*/

   /*std::vector<std::string> instructions;
    std::ifstream inputFile("instructions.txt");

    if (!inputFile) {
        std::cout << "Failed to open the instructions file." << std::endl;
        return 1;
    }

    std::string line;
    while (getline(inputFile, line)) {
        instructions.push_back(line);
    }

    inputFile.close();

    rom.storeData(instructions);*/
   //std::vector<std::string> instructions;
    cpu.ReadDataFromTextFile("instructions.txt");
    cpu.decodeAndExecute();

    int i = ram.getValue(3);
    std::cout<<i<<std::endl;



    /*const auto& romData = rom.getData();
    for (int i = 0; i < romData.size(); i++) {
        std::cout << "Address " << i << ": " << romData[i] << std::endl;
    }*/



    return 0;
}
