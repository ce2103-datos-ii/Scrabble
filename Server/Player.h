//
// Created by ivan on 3/24/19.
//

#ifndef SCRABBLE_SERVER_PLAYER_H
#define SCRABBLE_SERVER_PLAYER_H

#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <string>

using namespace std;

class Player {

private:
    char tiles[10];
    int score;
    bool turn;
    string id;
    int port;
    int playerSocket;
public:
    void setPlayerSocket(int playerSocket);

public:
    int getPlayerSocket() const;

public:
    const string &getId() const;

    int getPort() const;

    void setPort(int port);

public:
    void setId(const string &id);

    virtual ~Player();

    const char *getTiles() const;

    int getScore() const;

    void setScore(int score);

    bool isTurn() const;

    void setTurn(bool turn);

};


#endif //SCRABBLE_SERVER_PLAYER_H
