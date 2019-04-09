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
            Players::shared_instance().player1->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player1->setTurn(false);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(false);
            Players::shared_instance().player2->setTurn(true);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 2) {
            Players::shared_instance().player2->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player2->setTurn(false);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(false);
            Players::shared_instance().player3->setTurn(true);
            d1.Parse(jsonPlayer3);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 3) {
            Players::shared_instance().player3->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player3->setTurn(false);
            d1.Parse(jsonPlayer3);
            d1["turn"].SetBool(false);
            Players::shared_instance().player4->setTurn(true);
            d1.Parse(jsonPlayer4);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 4) {
            Players::shared_instance().player4->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player4->setTurn(false);
            d1.Parse(jsonPlayer4);
            d1["turn"].SetBool(false);
            Players::shared_instance().player1->setTurn(true);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(true);
        }
    } else if (playerCount == 3){
        if (d1["id"] == 1) {
            Players::shared_instance().player1->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player1->setTurn(false);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(false);
            Players::shared_instance().player2->setTurn(true);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 2) {
            Players::shared_instance().player2->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player2->setTurn(false);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(false);
            Players::shared_instance().player3->setTurn(true);
            d1.Parse(jsonPlayer3);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 3) {
            Players::shared_instance().player3->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player3->setTurn(false);
            d1.Parse(jsonPlayer3);
            d1["turn"].SetBool(false);
            Players::shared_instance().player1->setTurn(true);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(true);
        }
    } else if (playerCount == 2){
        if (d1["id"] == 1) {
            Players::shared_instance().player1->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player1->setTurn(false);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(false);
            Players::shared_instance().player2->setTurn(true);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(true);
        } else if (d1["id"] == 2) {
            Players::shared_instance().player2->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player2->setTurn(false);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(false);
            Players::shared_instance().player1->setTurn(true);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(true);
        }
    }

}

void Players::setPorts() {

    player1->setPort(54001);
    player2->setPort(54002);
    player3->setPort(54003);
    player4->setPort(54004);

}
