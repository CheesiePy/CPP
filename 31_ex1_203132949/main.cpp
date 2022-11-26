#include <iostream>
#include "winterGames.h"

int isNumber(const string& str)
{
    for(int i=0;i<int(str.length());i++) {
        if (isdigit(str[i]) == 0)
            return 0;
    }
    return 1;
}

int main(int argc, char** argv){
    char* judges = argv[1];
    char* players = argv[2];
    if(!isNumber(judges)|| !isNumber(players))
        cerr << "ERROR: USAGE <executable> NUM_REFEREES MAX_ATHLETES" <<endl;
    else
    {
        winterGames game(atoi(judges),atoi(players));

    }

}
