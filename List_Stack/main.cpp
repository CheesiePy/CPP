#include <iostream>
#include "Stack.h"

int main() {
    Stack s, x;
    x << 3 << 2 << 1;
    s << 5 << 6 << 7;
    x >> s;
    std::cout << s;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
