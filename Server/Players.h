//
// Created by ivan on 4/5/19.
//

#ifndef SCRABBLE_PLAYERS_H
#define SCRABBLE_PLAYERS_H

#include "Player.h"
#include "../rapidjson/document.h"
#include "../rapidjson/writer.h"
#include "../rapidjson/stringbuffer.h"
#include "HashMap.h"
#include "JsonParser.h"

using namespace rapidjson;

class Players {

private:
    int playerCount;
    int code;
    string matrix;
    string letters;
public:
    const string &getLetters() const;

    void setLetters(const string &letters);

public:
    const string &getMatrix() const;

    void setMatrix(const string &matrix);
    const char* jsonPlayer1 = "{\n"
                              "    \"turn\": false,\n"
                              "    \"score\": 3,\n"
                              "    \"id\": 0,\n"
                              "    \"matrix\": null,\n"
                              "    \"letters\": [],\n"
                              "    \"word\": null,\n"
                              "    \"port\": 54001\n"
                              "}";
    const char* jsonPlayer2 = "{\n"
                              "    \"turn\": false,\n"
                              "    \"score\": 3,\n"
                              "    \"id\": 0,\n"
                              "    \"matrix\": null,\n"
                              "    \"letters\": [],\n"
                              "    \"word\": null,\n"
                              "    \"port\": 54001\n"
                              "}";
    const char* jsonPlayer3 = "{\n"
                              "    \"turn\": false,\n"
                              "    \"score\": 3\n"
                              "    \"id\": 0\n"
                              "    \"matrix\": null\n"
                              "    \"letters\": []\n"
                              "    \"word\": null\n"
                              "    \"port\": 54001\n"
                              "}";
    const char* jsonPlayer4 = "{\n"
                              "    \"turn\": false,\n"
                              "    \"score\": 3\n"
                              "    \"id\": 0\n"
                              "    \"matrix\": null\n"
                              "    \"letters\": []\n"
                              "    \"word\": null\n"
                              "    \"port\": 54001\n"
                              "}";
public:
    void setPlayerJsons();
    void manageTurns(const char* json);
    long getCode() const;
    void setCode(int code);
    int getPlayerCount() const;
    void setPlayerCount(int playerCount);
    void deletePlayers();
    void setPorts();
    int checkTurn();
    void setPlayerTurns();
    Player *player1 = new Player;
    Player *player2 = new Player;
    Player *player3 = new Player;
    Player *player4 = new Player;

public:
    static Players &shared_instance() {static Players players; return players;}

private:
    // Make constructor private. Only shared_instance() method will create an instance.
    Players() {/*whatever initialisation you need*/}

};


#endif //SCRABBLE_PLAYERS_H
