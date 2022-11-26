#include <cmath>
#include <iomanip>
#include "Player.h"

int Player::numberOfPlayers = 0;
// c'tors
Player::Player(){}

Player::~Player() { // d'tor
    delete[] ScoreVector;
}

//Setters
void Player::setName(const string& str) {
    name = str;
}


//Getters
string Player::getName() const {
    return name;
}

void Player::setScoreVectorSize(int size) {
    scoreVectorSize = size;
}

Player::Player(int scoreVsize):ScoreVector(new float[scoreVsize]), scoreVectorSize(scoreVsize) {

}

void Player::setScoreVector() {
    float *temp(new float[scoreVectorSize]);
    string buffer, token;
    int counter = 0;

    cin >> buffer;
    istringstream ss(buffer);

    while(getline(ss, token, ','))
    {
        if(counter == scoreVectorSize) // if counter is longer then scoreVectorSize then there to many entries;
        {
            cout << "ERROR: invalid input" << endl;
            return;
        }
        temp[counter++] = atof(token.c_str());
    }
    // after the while itration we need to have counter == scoreVectorSize
    if(counter != scoreVectorSize)
    {
        cout << "ERROR: invalid input" << endl;
        return;
    }
    for(int i = 0; i<scoreVectorSize; i++)
        ScoreVector[i] = temp[i];
}

void Player::printPlayer() {
    cout << name << "=[";
    for(int i = 0; i < scoreVectorSize; i++)
    {
        if(i == scoreVectorSize-1)
            cout << ScoreVector[i];
        else
            cout << ScoreVector[i]<<",";
    }
    cout<<"]"<<endl;
}

void Player::printAvrgScore() {
    float avrg = 0.0;
    for(int i = 0; i < scoreVectorSize; i++)
        avrg+=ScoreVector[i];

    int precision = 0;
    if(avrg - roundf(avrg) != 0)
        precision = 2;
    cout << name << ", " << fixed << setprecision(precision) << avrg/(float)scoreVectorSize << endl;
}







