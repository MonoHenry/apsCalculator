#include <math.h>
#include "CpuRenri.hpp"
#include "KeyboardRenri.hpp"
#include <iostream>


Display *CpuRenri::getDisplay() { return this->display; }
void CpuRenri::setDisplay(Display *display) { this->display = display; }


KeyboardRenri Keyboard;


void CpuRenri::receiveDigit(Digit digit) {
  if(this->display!=nullptr){
    if(this->op == nullptr){
      this->display->add(digit);
      digit1[digit1Count] = digit;
      digit1Count++;
      if(!this->pointPressed){
        decimalPos1++;
      }
      
    }else{
      this->display->clear();
      this->display->add(digit);
      digit2[digit2Count] = digit;
      digit2Count++;
      if(!this->pointPressed){
      decimalPos2++;}
    }
  }
}

int CpuRenri::convertDigit(Digit digit){
  switch(digit){
    case ZERO: 
      return 0;
    case ONE: 
      return 1;
    case TWO: 
      return 2;
    case THREE: 
      return 3;
    case FOUR: 
      return 4;
    case FIVE: 
      return 5;
    case SIX: 
      return 6;
    case SEVEN: 
      return 7;
    case EIGHT: 
      return 8;
    case NINE: 
      return 9;
    default: 
       this->error = true;
       return 0;
  } 
}


Digit CpuRenri::convertInt(int num){
  switch(num){
    case 0: 
      return ZERO;
    case 1: 
      return ONE;
    case 2: 
      return TWO;
    case 3: 
      return THREE;
    case 4: 
      return FOUR;
    case 5: 
      return FIVE;
    case 6: 
      return SIX;
    case 7: 
      return SEVEN;
    case 8: 
      return EIGHT;
    case 9: 
      return NINE;
    default: 
       this->error = true;
       return ZERO;
  }
}


float CpuRenri::convertDigitsToFloat(Digit* digits, int digitCount, int decimalPos) {
    float result = 0.0f;
    for(int i = 0; i < digitCount; i++){
      result = (result * 10) + convertDigit(*(digits+i));
    }
    result = result / pow(10, digitCount - decimalPos);
    return result;
  }


void CpuRenri::convertFloatToDigits(Digit* digits, float num) {
    this->digit1Count = 0;
    float resultado = num;
    Digit temporary;
    int temp = num;
    int decTemp = 0;
    for(int i = 0; 1; i++){
      if(resultado-temp == 0){
        break;
      }else{
        resultado *= 10;
        temp = resultado;
        decTemp++;
      }
    }
    while(temp > 0){
      this->digit1[this->digit1Count++] = this->convertInt(temp % 10);
      temp /= 10;
    }
    for(int i = 0; i < this->digit1Count / 2; i++){
      temporary = this->digit1[i];
      digits[i] = digits[digit1Count - 1 - i];
      digits[digit1Count - 1 - i] = temporary;
    }
    this->decimalPos1 = temp;
  }
 

void CpuRenri::receiveOperator(Operator operator1) {
  delete this->op;
  this->op = new Operator;
  *this->op = operator1;
  this->pointPressed = 0;
  this->decimalPos2 = 0;
}


float CpuRenri::calculate(float num1, float num2){
    switch(*this->op){
      case SUM: 
        return num1+num2;
      case SUBTRACTION: 
        return num1-num2;
      case DIVISION: 
        return num1/num2;
      case MULTIPLICATION: 
        return num1*num2;
      case PERCENTAGE: 
        return num1*num2/100;
      case SQUARE_ROOT: 
        return sqrt(num1);
      default: 
        this->error = true;
        return 0;
  }
}


void CpuRenri::setDecimalSeparator(){
  this->pointPressed = 1;
  if(this->op == nullptr){
    this->decimalPos1 = digit1Count;
    this->display->setDecimalSeparator();
  }else{
    this->decimalPos2 = digit2Count;
    this->display->setDecimalSeparator();
  }
}


void CpuRenri::receiveControl(Control c) {
  switch(c){
    case EQUAL:
      this->num1 = convertDigitsToFloat(digit1, digit1Count, decimalPos1);
      std::cout << num1;
      this->num2 = convertDigitsToFloat(digit2, digit2Count, decimalPos2);
      this->num1 = calculate(num1, num2);
      convertFloatToDigits(digit1, num1);
      for(int i = 0; i < digit2Count; i++){
          digit2[i] = ZERO;
      }
      this->display->clear();
      for(int i = 0; i < this->digit1Count; i++){
        this->display->add(*(this->digit1+i));
        if(i == this->digit1Count - this->decimalPos1){ //antes era <
          this->display->setDecimalSeparator();
        }
      }
      break;
    case DECIMAL_SEPARATOR:
      setDecimalSeparator();
      break;
    case CLEAR_ERROR:
      break;
    case ON:
      break;
    case OFF:
      break;
    case MEMORY_SUM:
      break;
    case MEMORY_SUBTRACTION:
      break;
    case MEMORY_READ_CLEAR:
      break;
  } 
}
