#ifndef LAB09_HORSE_H
#define LAB09_HORSE_H
#include "Animal.h"
#endif //LAB09_HORSE_H

class Horse : public Animal{
public:
    Horse(): Animal() {}
    virtual void speak() { cout << "Hay im a Horse and my name is " << getName() <<endl;}
 };
