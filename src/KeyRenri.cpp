#include "KeyRenri.hpp"

KeyBase::KeyBase(Symbol symbol) { this->symbol = symbol; }

Symbol KeyBase::getSymbol() { return this->symbol; }

void KeyBase::setKeyboard(Keyboard *keyboard) { this->keyboard = keyboard; }
Keyboard *KeyBase::getKeyboard() { return this->keyboard; }

KeyDigitRenri::KeyDigitRenri(Symbol symbol, Digit digit) : KeyBase(symbol) {
  this->digit = digit;
}

Digit KeyDigitRenri::getDigit() { return this->digit; }

void KeyDigitRenri::press(){
  this->getKeyboard()->getCpu()->receiveDigit(this->digit);
}

KeyOperatorRenri::KeyOperatorRenri(Symbol symbol, Operator operator_) : KeyBase(symbol) {
  this->operator_ = operator_;
}

Operator KeyOperatorRenri::getOperator() { return this->operator_; }

void KeyOperatorRenri::press(){
  this->getKeyboard()->getCpu()->receiveOperator(this->operator_);
}

KeyControlRenri::KeyControlRenri(Symbol symbol, Control control) : KeyBase(symbol) {
  this->control = control;
}

Control KeyControlRenri::getControl() { return this->control; }

void KeyControlRenri::press(){
  this->getKeyboard()->getCpu()->receiveControl(this->control);
}
