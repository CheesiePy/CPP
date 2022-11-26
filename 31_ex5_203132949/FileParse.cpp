#include "FileParse.h"
#include <fstream>
#include <sstream>
#include <cstdlib>

FileParse::FileParse() {}

FileParse::~FileParse() {}



void FileParse::load(const string& fileName, double **graph, uint psize, uint ssize){
    //cout << fileName << endl;
    fstream file;
    stringstream num_parser; // for parsing numbers (float or integers) and validating them using stringstream.
    file.open(fileName.c_str(), ios::in);

    if( !file ){
        cerr << "ERROR: " << fileName << " does not exist or cannot be opened" << endl;
        exit(-1);
    }

    string line;
    getline(file, line);
    if( file.eof() ){
        cerr << "ERROR: Invalid input." << endl;
        exit(-1);
    }

    if( num_parser.fail() ){
        cerr << "ERROR: Invalid input." << endl;
        exit(-1);
    }

    double temp_val;
    int lineC = 1;
    for(uint i = 0; i < psize; i++)  {
        num_parser.clear();
        getline(file, line);
        if( file.eof() )    {
            continue;
        }
        lineC++;
        num_parser.str(line);
        uint count = 0;
        uint k = 0;
        while(line[k] != '\0'){
            if(line[k] == ' ')
                count++;
            k++;
        }
        if(count >= ssize){
            cerr << "ERROR: population definition in " << fileName << " at line " << lineC << " is invalid" << endl;
            exit(-1);
        }
        for(uint j = 0; j < ssize; j++)  {
            num_parser >> temp_val;
            if( num_parser.fail() ) {
                continue;
            }
            graph[i][j] = (temp_val);
        }
    }
    file.close();

}

void FileParse::load(const string& fileName, uint& numberOfElement, uint& sizeOfSource, uint& sizeOfDest, uint& ticks){
    fstream file;
    stringstream num_parser; // for parsing numbers (float or integers) and validating them using stringstream.
    file.open(fileName.c_str(), ios::in);
    if( !file ){
        cerr << "ERROR: " << fileName << " does not exist or cannot be opened" << endl;
        exit(-1);
    }
    string buffer;
    getline(file,buffer);

    if(file.eof()){
        cerr << "ERROR: " << fileName << " does not exist or cannot be opened" << endl;
        exit(-1);
    }

    num_parser.str(buffer);
    num_parser >> numberOfElement;
    if(num_parser.fail()){
        cerr << "ERROR: simulation definition in " << fileName << " is invalid" << endl;
        exit(-1);
    }
    num_parser >> sizeOfSource;
    if(num_parser.fail()){
        cerr << "ERROR: simulation definition in " << fileName << " is invalid" << endl;
        exit(-1);
    }
    num_parser >> sizeOfDest;
    if(num_parser.fail()){
        cerr << "ERROR: simulation definition in " << fileName << " is invalid" << endl;
        exit(-1);
    }
    if(sizeOfDest > sizeOfSource){
        cerr << "ERROR: simulation definition in " << fileName << " is invalid" << endl;
        exit(-1);
    }
    num_parser >> ticks;
    if(num_parser.fail()){
        cerr << "ERROR: simulation definition in " << fileName << " is invalid" << endl;
        exit(-1);
    }
    file.close();
}
