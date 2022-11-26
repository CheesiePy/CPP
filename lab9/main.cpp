#include <iostream>
#include "Donkey.h"
int main() {
    Animal* a = new Donkey(true,"lidia");
    a->speak();
    return 0;
}
