#include <iostream>
#include <malloc.h>
#include <cstring>
#include <cstdlib>
#include <stack>


using namespace std;

struct Real {
    double value;
};

struct Complex{
    Real a;
    Real b;

};

Complex* complexAddition(Complex a, Complex b){
    Complex* c = (Complex*)malloc(sizeof(Complex));
    c->a.value = a.a.value + b.a.value;
    c->b.value = a.b.value + b.b.value;
    return c;
}

Complex* complexSubtract(Complex a, Complex b){
    Complex* c = (Complex*)malloc(sizeof(Complex));
    c->a.value = (a.a.value*b.a.value)+(a.b.value*b.b.value);
    c->b.value = (a.b.value*b.a.value)+(a.a.value*b.b.value);
    return c;
}

Complex* complexMultiply(Complex a, Complex b){
    Complex* c = (Complex*)malloc(sizeof(Complex));
    c->a.value = a.a.value * b.a.value;
    c->b.value = a.b.value * b.b.value;
    return c;
}


Complex* complexArithmetics(Complex a, Complex b,  Complex* pFunction(Complex a, Complex b)){
    Complex* c = pFunction(a, b);
    return c;
};

//string complexFormat(Complex a){
//
//    string realA, imgA;
//    realA = str(a.a.value);
//}

int main() {
    int lock = -1;
    while (lock < 0){
        string a;
        cin >> a;
        if(a.length() > (stack.top()).length()){
            string temp = (string) stack.pop();

        }
        if(a == "Quit"){
            cout << a << endl;
            exit(1);
        }

        cout << a << endl;
    }



    return 0;
}
