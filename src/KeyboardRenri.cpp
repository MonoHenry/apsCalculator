#include "KeyboardRenri.hpp"
#include "cstring"


void KeyboardRenri::addKey(Key *key) {
for(int i = 0; i < this->keysCount; i++)
    if(this->keys[i]==key) throw "Repeated key!";

  this->keys[this->keysCount++] = key;
  key->setKeyboard(this);
}


void KeyboardRenri::removeKey(Key *key) { 
  for(int i = 0; i < this->keysCount; i++){
    if(this->keys[i] == key){
      this->keysCount--;
      for(int j = i; j < this->keysCount; j++){
        this->keys[j] = this->keys[j+1];
      }
      break;
    }
  }
}


Key *KeyboardRenri::findKey(Symbol symbol) {
  for (char i = 0; i < this->keysCount; i++)
    if (strcmp(symbol,this->keys[i]->getSymbol()))
      return this->keys[i];
  throw "Key not found!";
}


void KeyboardRenri::setCpu(Cpu *cpu){
   this->cpu = cpu;
}


Cpu *KeyboardRenri::getCpu(){
   return this->cpu;
}
