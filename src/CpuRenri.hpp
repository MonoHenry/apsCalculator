#pragma once

#include "CalculatorInterfaces.hpp"

class CpuRenri: public Cpu{
  

  private:
    Display* display; 
    float num1;
    float num2;
    Digit digit1[8];
    Digit digit2[8];
    int digit1Count;
    int pointPressed = 0;
    int digit2Count;
    Operator *op = nullptr;
    Control *control = nullptr;
    float calculate(float, float);
    int decimalPos1 = 0;
    int decimalPos2 = 0;
    bool error = false;    


  public:

    void setDecimalSeparator();
    int convertControl(Control);
    Display* getDisplay();
    void receiveDigit(Digit);
    void receiveOperator(Operator);
    void receiveControl(Control);
    float convertDigitsToFloat(Digit*, int, int);
    void convertFloatToDigits(Digit*, float);
    int convertDigit(Digit);
    Digit convertInt(int);
    void setDisplay(Display*);
    void show(Digit*, int);
   
};
