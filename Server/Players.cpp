//
// Created by ivan on 4/5/19.
//

#include "Players.h"

int Players::getPlayerCount() const {
    return playerCount;
}

void Players::setPlayerCount(int playerCount) {
    Players::playerCount = playerCount;
}

void Players::deletePlayers() {
    if (playerCount == 2){
        delete player3;
        delete player4;
    } else if (playerCount == 3)
        delete player4;
}

long Players::getCode() const {
    return code;
}

void Players::setCode(int code) {
    Players::code = code;
}

void Players::manageTurns() {
    Document d1;
    if (playerCount == 4) {
        if (d1["id"] == 1) {
            players->player1->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            players->player1->setTurn(false);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(false);
            players->player2->setTurn(true);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 2) {
            players->player2->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            players->player2->setTurn(false);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(false);
            players->player3->setTurn(true);
            d1.Parse(jsonPlayer3);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 3) {
            players->player3->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            players->player3->setTurn(false);
            d1.Parse(jsonPlayer3);
            d1["turn"].SetBool(false);
            players->player4->setTurn(true);
            d1.Parse(jsonPlayer4);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 4) {
            players->player4->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            players->player4->setTurn(false);
            d1.Parse(jsonPlayer4);
            d1["turn"].SetBool(false);
            players->player1->setTurn(true);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(true);
        }
    } else if (playerCount == 3){
        if (d1["id"] == 1) {
            players->player1->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            players->player1->setTurn(false);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(false);
            players->player2->setTurn(true);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 2) {
            players->player2->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            players->player2->setTurn(false);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(false);
            players->player3->setTurn(true);
            d1.Parse(jsonPlayer3);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 3) {
            players->player3->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            players->player3->setTurn(false);
            d1.Parse(jsonPlayer3);
            d1["turn"].SetBool(false);
            players->player1->setTurn(true);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(true);
        }
    } else if (playerCount == 2){
        if (d1["id"] == 1) {
            players->player1->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            players->player1->setTurn(false);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(false);
            players->player2->setTurn(true);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 2) {
            players->player2->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            players->player2->setTurn(false);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(false);
            players->player1->setTurn(true);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(true);
        }
    }

}
