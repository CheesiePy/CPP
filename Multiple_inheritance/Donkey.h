#ifndef LAB09_DONKEY_H
#define LAB09_DONKEY_H
#include "Animal.h"
class Donkey : public Animal{
public:
    Donkey(): Animal(){}
    Donkey(bool gender, const string& name): Animal(gender,name){};
    virtual void speak() { cout << "Hay im a Donkey and my name is " << getName() <<endl;}
};

#endif //LAB09_DONKEY_H
