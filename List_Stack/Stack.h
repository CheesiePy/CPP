//
// Created by Mai on 12/8/2021.
//

#ifndef CPP_LAB07_STACK_H
#define CPP_LAB07_STACK_H


#include "List.h"

class Stack {
    public:
    // operators
    int operator*() const;

    void operator~();

    bool operator!() const;

    Stack& operator<<(int x);

    Stack& operator>>(int& x);

    Stack& operator<<(Stack& other);

    Stack& operator>>(Stack& other);

    friend ostream& operator<<(ostream& out, const Stack &s);

    // class methods
    void push(int x);
    int pop();
    int top() const;
    bool empty() const;
    void transfer(Stack &other);

    private:
    List list;
};



#endif //CPP_LAB07_STACK_H
