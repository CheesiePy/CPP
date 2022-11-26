#ifndef POLLUTIONSIMULATOR_FILEPARSE_H
#define POLLUTIONSIMULATOR_FILEPARSE_H
#include <iostream>
#include <fstream>
#include <cstdlib>
/*
 * to use write file you must include << operator in you class object
 *
 * */

using namespace std;


class FileParse {
public:
    //
    FileParse();
    // d'tor
    ~FileParse();
    void load(const string& fileName, double **graph,uint psize, uint ssize);
    void load(const string& fileName, uint& numberOfElement, uint& sizeOfSource, uint& sizeOfDest, uint& ticks);


    template <class T>
    void Write(const string& fileName, const T& content){
        ofstream file;
        file.open(fileName.c_str(), ios::out);
        if( !file ){
            cerr << "ERROR: Invalid input." << endl;
            exit(-1);
        }
        file << content;
    }
private:
    // = operator
    FileParse& operator=(const FileParse& other);


};


#endif //POLLUTIONSIMULATOR_FILEPARSE_H
