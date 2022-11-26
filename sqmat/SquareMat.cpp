//
// Created by Mai on 11/17/2021.
//

#include <iostream>
#include "SquareMat.h"

SquareMat::SquareMat(int d):ndim(d)
{
    std::cout << "starting" << std::endl;
    data =  new int*[d];
    for(int i = 0; i < d; i++){
        data[i] = new int[d];
        for(int j = 0; j < d; j++){
            int random, sign;
            random = rand()%101;
            sign = rand()%2;
            if (sign == 0)
                random = random * -1;
            data[i][j] = random;
        }
    }
}

SquareMat::SquareMat(const SquareMat &sq) {
    ndim = sq.ndim;
    data = sq.data;
    std::cout << "Ouch!" << std::endl;

}

void SquareMat::printSQ() {
    for(int i = 0; i < )

}
