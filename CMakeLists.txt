cmake_minimum_required(VERSION 3.26)
project(TaskOne)

set(CMAKE_CXX_STANDARD 17)

add_executable(TaskOne main.cpp
        Memory.h
        RAM.h
        ROM.h
        CPU.h
        Instruction.h
        SetInstruction.h
        AddInstruction.h
        AddiInstruction.h
        PrintInstruction.h
        JumpInstruction.h
)
