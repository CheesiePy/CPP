#include <iostream>
#include "Dictionary.h"
int main() {
    Dictionary<int , string>  d = Dictionary<int, string>();
    int k = 1;
    string v = "may";
    d.put(k, v);
    d.put(5,"yugi");
    d.put(10,"mooncake");
    cout << d.get(k);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
