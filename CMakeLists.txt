cmake_minimum_required(VERSION 3.26)
project(TaskOne)

set(CMAKE_CXX_STANDARD 17)

add_executable(TaskOne main.cpp
        Memory/Memory.h
        Memory/RAM.h
        Memory/ROM.h
        CPU/CPU.h
        Instruction/Instruction.h
        Instruction/SetInstruction.h
        Instruction/AddInstruction.h
        Instruction/AddiInstruction.h
        Instruction/PrintInstruction.h
        Instruction/JumpInstruction.h
)
