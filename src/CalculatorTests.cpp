#include "CalculatorTests.hpp"
#include <iostream>

bool CalculatorTests::pauseAfterTests = false;
void CalculatorTests::setPauseAfterTests(bool value) {
  CalculatorTests::pauseAfterTests = value;
}

void CalculatorTests::pause() {
  std::cout << "\nPRESS ENTER TO CONTINUE:";
  std::cin.ignore();
}

void CalculatorTests::testDisplay(Display *display) {
  display->clear();
  display->setError(true);
  display->setMemory(true);
  display->setNegative(true);
  for (int i = 0; i < Display::MAX_DIGITS; i++)
    display->add(Digit::EIGHT);

  if (CalculatorTests::pauseAfterTests)
    CalculatorTests::pause();
}

void CalculatorTests::testCpu(Cpu *cpu, Display *display) {
  cpu->setDisplay(display);
  cpu->receiveDigit(Digit::ONE);
  cpu->receiveDigit(Digit::FOUR);
  cpu->receiveOperator(Operator::MULTIPLICATION);
  cpu->receiveDigit(Digit::TWO);
  cpu->receiveControl(Control::EQUAL);
  std::cout << "\n";
  if (CalculatorTests::pauseAfterTests)
    CalculatorTests::pause();
}

void CalculatorTests::testKeyboard(Keyboard *keyboard) {
  // keyboard->addKey(new KeyDigit()));

  if (CalculatorTests::pauseAfterTests) CalculatorTests::pause();
}
