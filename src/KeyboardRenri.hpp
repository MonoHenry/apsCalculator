#pragma once

#include "CalculatorInterfaces.hpp"

class KeyboardRenri: public Keyboard{
    static const char MAX_KEYS = 101;

    Key* keys[MAX_KEYS];
    int keysCount = 0;
    Cpu* cpu;
    
  public:
    void addKey(Key*);
    void removeKey(Key*);
    Key* findKey(Symbol);
    void setCpu(Cpu*);
    Cpu* getCpu();
};