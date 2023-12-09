#pragma once

#include "CalculatorInterfaces.hpp"

class KeyBase: public virtual Key{
  Keyboard* keyboard;
  Symbol symbol;
  public:
    KeyBase(Symbol);

    Symbol getSymbol();

    void setKeyboard(Keyboard*);
    Keyboard* getKeyboard();
};

class KeyDigitRenri: public KeyBase, public KeyDigit{
  Digit digit;

  public:
    KeyDigitRenri(Symbol, Digit);

    Digit getDigit();

    void press();
};


class KeyOperatorRenri: public KeyBase, public KeyOperator{
  Operator operator_;

  public:
    KeyOperatorRenri(Symbol, Operator);

    Operator getOperator();

    void press();
};


class KeyControlRenri: public KeyBase, public KeyControl{
  Control control;

  public:
    KeyControlRenri(Symbol, Control);

    Control getControl();

    void press();
};

