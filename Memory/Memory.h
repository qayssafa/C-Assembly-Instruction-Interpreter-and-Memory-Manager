
#include "vector"
#include "string"
#pragma once
class Memory {
protected:
    std::vector<std::string > data;
public:
    Memory(int size):data(size) {}
  int getValue(int address) const {
      return std::stoi(data[address]);
  }
    const std::vector<std::string>& getData() const {
        return data;
    }
    virtual ~Memory() {}
};


