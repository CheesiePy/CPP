//
// Created by Mai on 11/17/2021.
//

#ifndef LAB04_SQUAREMAT_H
#define LAB04_SQUAREMAT_H
#include <cstdlib>


class SquareMat {
public:
    SquareMat(int d);
    SquareMat(const SquareMat &sq);
    int** getData(){return data;}
    void printSQ();

private:
    int **data;
    int ndim;
};


#endif //LAB04_SQUAREMAT_H
