#include "Memory/RAM.h"
#include "Memory/ROM.h"
#include "CPU/CPU.h"
#define RAM_SIZE 255
#define ROM_SIZE 15
#define FILE_NAME "instructions.txt"


int main() {
    RAM ram(RAM_SIZE);
    ROM rom(ROM_SIZE);
    CPU cpu(rom , ram);

    cpu.start(FILE_NAME);

    return 0;
}
