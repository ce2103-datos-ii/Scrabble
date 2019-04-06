//
// Created by ivan on 3/24/19.
//

#ifndef SCRABBLE_SERVER_PLAYER_H
#define SCRABBLE_SERVER_PLAYER_H

#include <iostream>

using namespace std;

class Player {

private:
    char tiles[10];
    int score;
    bool turn;
    int id;

public:

    const char *getTiles() const;

    int getScore() const;

    void setScore(int score);

    bool isTurn() const;

    void setTurn(bool turn);

    int getId() const;

};


#endif //SCRABBLE_SERVER_PLAYER_H
