#include "RAM.h"
#include "ROM.h"
#include "CPU.h"
#define RAM_SIZE 255
#define ROM_SIZE 15


int main() {
    RAM ram(RAM_SIZE);
    ROM rom(ROM_SIZE);
    CPU cpu(rom , ram);

    cpu.start("instructions.txt");

    return 0;
}
