#include <iostream>
#include "Input.h"



int UserInput::getUserChoice(){
    int userInput;
    cin >> userInput;

    cin.seekg(0,ios::end); // push pointer to the end of the cin stream
    cin.clear();           // clear all errors and EOF flags


    if (userInput > 6 || userInput < 0)
        return -1;
    return userInput;
}
string UserInput::getUserStr() {
    string userStr;
    getline(cin,userStr);
    return userStr;
}

