#include <cmath>
#include "winterGames.h"
using namespace UserInput;
winterGames::winterGames(int judgeNumber, int playerNumber):judgeNumber(judgeNumber), playerNumber(playerNumber){
    playerVector = new Player[playerNumber];
}

winterGames::~winterGames() {
    delete[] playerVector;
    delete[] JudgeAvrgArray;
}


winterGames::winterGames() {}

int winterGames::playerIndex(string name) {
    for(int i = 0; i < playerNumber; i++){
        if(name == playerVector[i].getName())
            return i;
    }
    return -1;



}

void winterGames::printPlayerAvrg(string& name) {
    int index = playerIndex(name);
    if(index < 0){
        cout << "ERROR: "<< name << " does not exist" << endl;
        return;
    }
    playerVector[index].printAvrgScore();
}


void winterGames::printAllplayrsAvrg() {
    if (!isEmpty())
        for (int i = 0; i < Player::numberOfPlayers; i++)
            playerVector[i].printAvrgScore();
    cout << "ERROR: no records in the system" << endl;
}

bool winterGames::isEmpty() {
    if(!Player::numberOfPlayers)
    {
        cout << "ERROR: no records in the system" << endl;
        return true;
    }
    return false;
}

void winterGames::addPlayer(string &name) {
    int index = playerIndex(name);

    if(index < 0)
    {
        playerVector[Player::numberOfPlayers].setScoreVector();
        playerVector[Player::numberOfPlayers].setName(name);
        Player::numberOfPlayers++;
    }
    else
        playerVector[index].setScoreVector();
}

void winterGames::judgeAvrg() {
    if(isEmpty())
        cout << "ERROR: no records in the system" << endl;
    float avrg;
    int judge = 0;
    for(int i = 0; i < judgeNumber; i++)
    {
        avrg = 0;
        for(int j = 0; i < judgeNumber; i++)
            avrg += playerVector[j].ScoreVector[i];

        avrg/=(float)Player::numberOfPlayers;

        if(avrg - roundf(avrg) == 0)
            JudgeAvrgArray[judge++] = roundf(avrg);
        else
            JudgeAvrgArray[judge++] = roundf(avrg*100)/100;
    }
}

void winterGames::printJudgeAvrg() {
    cout<<"mean=[";
    for(int i =0;i<judgeNumber;i++)
    {
        if(i == judgeNumber-1)
            cout<<JudgeAvrgArray[i];
        else
            cout<<JudgeAvrgArray[i]<<",";
    }
    cout<<"]"<<endl;
}

void winterGames::printCovariantMatrix() {
    if(isEmpty())
        cout << "ERROR: no records in the system" << endl;
    judgeAvrg(); // populate...
    float covariance;
    cout<<"cov=["<<endl;
    for (int i = 0; i < judgeNumber; i++)
    {
        for(int j = 0; i < judgeNumber; i++) {
            covariance = 0;
            for (int k = 0; k < Player::numberOfPlayers; k++)
                covariance += (playerVector[k].ScoreVector[i]) * (playerVector[k].ScoreVector[i] - JudgeAvrgArray[j]);

            if (Player::numberOfPlayers > 1)
                covariance /= (float) Player::numberOfPlayers - 1;

            if(covariance - roundf(covariance) == 0)
                covariance = roundf(covariance);
            else
                covariance = roundf(covariance * 100)/100;

            if(j == judgeNumber-1)
                cout<<covariance;
            else
                cout<<covariance<<",";

            cout<<endl;
        }
        cout<<"]"<<endl;
    }


}

void winterGames::mainMenu() {

    int userChoice = 8;
    while(true)
    {
        cout << "[0] - Exit system\n"
                "[1] - Enter Judge score for a Player\n"
                "[2] - Show Judge score for a Player\n"
                "[3] - Show Player Average Score\n"
                "[4] - Print Average For all players\n"
                "[5] - Print Judge Average Vector\n"
                "[6] - Print Covariance Matrix"<< endl;

        cin >> userChoice;
        if(userChoice == 0)
                return;
        else if(userChoice == 1)
        {
            if (Player::numberOfPlayers == playerNumber) {
                cout << "ERROR: MAX_ATHLETES exceeded" << endl;
                continue;
            }
            string name = UserInput::getUserStr();
            addPlayer(name);
        }
        else if(userChoice == 2)
        {
            string name = UserInput::getUserStr();
            printPlayer(name);
        }
        else if(userChoice == 3)
        {
            string name = UserInput::getUserStr();
            printPlayerAvrg(name);

        }
        else if(userChoice == 4)
        {
            printAllplayrsAvrg();
        }
        else if(userChoice == 5)
        {
            judgeAvrg();
            printJudgeAvrg();
        }
        else if(userChoice == 6)
        {
            printCovariantMatrix();
        }
        else{
            cout << userChoice;
            cout << "ERROR: invalid command; type 0 for exit" << endl;
        }

        }
    }

void winterGames::printPlayer(string& name) {
    int index = playerIndex(name);
    if(index < 0)
        cout << "ERROR: "<< name << " does not exist" << endl;
    playerVector[index].printPlayer();
}


