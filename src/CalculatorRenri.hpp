#pragma once
#include "CalculatorInterfaces.hpp"

class CalculatorLucio: public Calculator{
  Keyboard* keyboard;
  Cpu* cpu;
  Display* display;
   
  public:
  // Getters and Setters    
void setDisplay(Display* );
Display* getDisplay(); 
void setCpu(Cpu* );
Cpu* getCpu();
void setKeyboard(Keyboard* );
Keyboard* getKeyboard();
};