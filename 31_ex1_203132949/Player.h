#ifndef WINTERGAMES_PLAYER_H
#define WINTERGAMES_PLAYER_H
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>

#include "Input.h"
using namespace std;

class Player {
public:

    Player();
    explicit Player(int scoreVsize);
    ~Player(); // d'tor

    //Setters
    void setName(const string&);
    void setScoreVector();
    void setScoreVectorSize(int size);
    //Getters
    string getName() const;


    //class methods
    void printPlayer();
    void printAvrgScore();

    // static fields
    static int numberOfPlayers;

private:
    friend class winterGames;
    int scoreVectorSize;
    string name;
    float* ScoreVector;
    Player(const Player& rhs); // copy c'tor every player is unique so copy c'tor is disabled
};


#endif //WINTERGAMES_PLAYER_H
