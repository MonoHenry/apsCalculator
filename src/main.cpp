#include "CalculatorTests.hpp"

#include "DisplayRenri.hpp"
#include "KeyboardRenri.hpp"
#include "KeyRenri.hpp"
#include "CpuRenri.hpp"

#include <iostream>

int main() {

  Display* display1 = new DisplayRenri();

  Cpu* cpu1 = new CpuRenri();

  /*Key* keyOne = new KeyDigitRenri("1", Digit::ONE);
  Key* keyOperator = new KeyOperatorRenri("+", Operator::SUBTRACTION);
  Key* keyControl = new KeyControlRenri("=", Control::EQUAL);*/

  Keyboard* keyboard1 = new KeyboardRenri();

   /*Build Calculator*/ 
  cpu1->setDisplay(display1);
  keyboard1->setCpu(cpu1);
  
  /*keyboard1->addKey(keyOne);
  keyboard1->addKey(keyOperator);
  keyboard1->addKey(keyControl);*/
  
  // /* Testing... */
  try{
    CalculatorTests::testCpu(cpu1, display1);
  }catch(const char* bolinha){
    std::cout << bolinha;
  }
  
  // CalculatorTests::pause();
  // CalculatorTests::setPauseAfterTests(true);

  // CalculatorTests::testDisplay(display1);
  // CalculatorTests::testKeyboard(keyboard1);

  delete display1;
  delete cpu1;
  delete keyboard1;
   
  // display1->showDigits();
  // std::cout<< "\nPRESS ENTER"; std::cin.ignore();
  // display1->mostrarDigitos();
  // std::cout<< "\nPRESS ENTER"; std::cin.ignore();


  // display1->Display::showDigits();
  // std::cout<< "\nPRESS ENTER"; std::cin.ignore();
  // display1->showDigits();
  // std::cout<< "\nPRESS ENTER"; std::cin.ignore();


  // Calculator calculator1;

  // calculator1.getKeyboard().getKey("1").press();
  // calculator1.getKeyboard().getKey("+").press();
  //calculator1.getKeyboard().getKey("1").press();
  //calculator1.getKeyboard().getKey("=").press();
}
