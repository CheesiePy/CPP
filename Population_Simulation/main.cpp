#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Simulation.h"




int main(int argc, char ** argv)    {
    srand((unsigned) time(NULL));
    if( argc > 3 ) {
        cout << "ERROR: invalid numbers of arguments to program." << endl;
        exit(1); // TODO : handle correctly according to exercise requirements.
    }
    Simulation s;
    s.load(string(argv[1]));





    return 0;
}
