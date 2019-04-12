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
#include "../rapidjson/rapidjson.h"
#include "../rapidjson/document.h"
#include "../rapidjson/stringbuffer.h"
#include "../rapidjson/writer.h"

using namespace std;
using namespace rapidjson;

class Player {

private:
    char tiles[10];
    int score;
    bool turn;
    string id;
    int port;
    int playerSocket;
    const char* json = "{\n"
                       "    \"turn\": false,\n"
                       "    \"score\": 3,\n"
                       "    \"id\": 0,\n"
                       "    \"matrix\": null,\n"
                       "    \"letters\": [],\n"
                       "    \"word\": null,\n"
                       "    \"port\": 54001\n"
                       "}";
    string letters;
public:
    const string &getLetters() const;

    void setLetters(const string &letters);

public:
    const char* getJson() const;

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
