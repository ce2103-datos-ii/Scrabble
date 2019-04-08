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
    HashMap hashMap;
    extern Players *players;
    const char* jsonPlayer1 = "{\n"
                              "    \"turn\": false,\n"
                              "    \"score\": 3\n"
                              "    \"id\": 0\n"
                              "    \"matrix\": null\n"
                              "    \"letters\": []\n"
                              "}";
    const char* jsonPlayer2 = "{\n"
                              "    \"turn\": false,\n"
                              "    \"score\": 3\n"
                              "    \"id\": 0\n"
                              "    \"matrix\": null\n"
                              "    \"letters\": []\n"
                              "}";
    const char* jsonPlayer3 = "{\n"
                              "    \"turn\": false,\n"
                              "    \"score\": 3\n"
                              "    \"id\": 0\n"
                              "    \"matrix\": null\n"
                              "    \"letters\": []\n"
                              "}";
    const char* jsonPlayer4 = "{\n"
                              "    \"turn\": false,\n"
                              "    \"score\": 3\n"
                              "    \"id\": 0\n"
                              "    \"matrix\": null\n"
                              "    \"letters\": []\n"
                              "}";
public:
    void manageTurns();
    long getCode() const;
    void setCode(int code);
    int getPlayerCount() const;
    void setPlayerCount(int playerCount);
    void deletePlayers();
    Player *player1 = new Player;
    Player *player2 = new Player;
    Player *player3 = new Player;
    Player *player4 = new Player;

};


#endif //SCRABBLE_PLAYERS_H
