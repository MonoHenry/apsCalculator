#include "CalculatorRenri.hpp"

 
void CalculatorLucio::setDisplay(Display* display){
  this->display = display;
if(this->cpu!=nullptr) this->cpu->setDisplay(display);
  }
Display* CalculatorLucio::getDisplay(){
  return this->display;
  } 
void CalculatorLucio::setCpu(Cpu* cpu){
  this->cpu = cpu;
  }
Cpu* CalculatorLucio::getCpu(){
  return cpu;
  }
void CalculatorLucio::setKeyboard(Keyboard* keyboard){
  this->keyboard = keyboard;
}
Keyboard* CalculatorLucio::getKeyboard(){
  return keyboard;
  }
