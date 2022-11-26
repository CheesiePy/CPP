//
// Created by Mai on 12/8/2021.
//

#include "Stack.h"

int Stack::operator*() const {
    return this->top();
}

void Stack::operator~() {
    list.clear();
}

bool Stack::operator!() const {
    return this->empty();
}

Stack &Stack::operator<<(int x) {
    this->list.insert(x);
    return *this;
}

Stack &Stack::operator>>(int &x) {
    x = this->pop();
    return *this;
}

Stack &Stack::operator<<(Stack &other) {
    other.transfer(*this);
    return *this;
}

Stack &Stack::operator>>(Stack &other) {
    this->transfer(other);
    return *this;
}

void Stack::push(int x) {
    list[list.size()-1] = x;
}

int Stack::pop() {
    int elem = top(); // first elem in list
    list.remove(elem);
    return elem;
}

int Stack::top() const {
    return list[0];
}

bool Stack::empty() const {
    if(list.size() == 0)
        return true;
    return false;

}

void Stack::transfer(Stack &other) {
    while(!empty())
    {
        int x = this->pop();
        other.list.insert(x);
    }

}

ostream& operator<<(ostream& out, const Stack &s){
    out << s.list << endl;
    return out;
}