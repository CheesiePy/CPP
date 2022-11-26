#ifndef WINTERGAMES_WINTERGAMES_H
#define WINTERGAMES_WINTERGAMES_H
#include "Player.h"

class winterGames {
// this will be the game manager
public:

    // c'tor
    winterGames(int judgeNumber, int playerNumber);
    winterGames();
    // d'tor
    ~winterGames();

    // class methods
    void mainMenu();
    bool isEmpty();

    //player setups
    void addPlayer(string &name);
    int playerIndex(string name);
    void printPlayerAvrg(string& name);
    void printAllplayrsAvrg();
    void printPlayer(string& name);

    //Judge methods
    void judgeAvrg();
    void printJudgeAvrg();

    // covariance matrix
    void printCovariantMatrix();


private:
    Player* playerVector;
    int playerNumber;
    int judgeNumber;
    float* JudgeAvrgArray;
};


#endif //WINTERGAMES_WINTERGAMES_H
