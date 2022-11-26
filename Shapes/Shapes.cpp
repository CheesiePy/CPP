//
// Created by Mai on 12/22/2021.
//

#include <iostream>
#include "Shapes.h"

void Square::Draw(char symbol) {
    for (int i = 0; i < GetSide(); i++) {
        for(int j = 0; j < GetSide(); j++){
            if(j == GetSide()-1){
                std::cout << symbol << std::endl;
            }else if(i == 0){
                std::cout << symbol << " ";
            }else if(j == 0){
                std::cout << symbol << " ";
            }else if(i == GetSide()-1){
                std::cout << symbol << " ";
            }else{
                std::cout << "  ";
            }
        }

    }
}

void RightTriangle::Draw(char symbol) {
    for (int i = 0; i < getBaseSize(); i++)
    {
        for(int j = 0; j < i + 1; j++)
        {
            if(j == i)
            {
                cout << symbol << endl;
            }else if(j == 0)
            {
                cout << symbol;

            }else if(i == getBaseSize()-1)
            {
                cout << symbol;
            }else
            {
                cout << " ";
            }
        }
    }
}
