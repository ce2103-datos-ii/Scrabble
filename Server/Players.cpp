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

void Players::manageTurns(const char* json) {
    cout << "entra" << endl;
    Document d1;
    Document d2;
    d1.Parse(json);
    assert(d1.IsObject());
    const char* char1;
    string buffString1;
    const char* char2;
    string buffString2;

    if (playerCount == 4) {
        if (d1["id"].GetString() == player1->getId()) {
            Players::shared_instance().player1->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player1->setTurn(false);
            d1.Parse(jsonPlayer1);
            d1["turn"].SetBool(false);
            Players::shared_instance().player2->setTurn(true);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(true);
        } else if (d1["id"].GetString() == player2->getId()) {
            Players::shared_instance().player2->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player2->setTurn(false);
            d1.Parse(jsonPlayer2);
            d1["turn"].SetBool(false);
            Players::shared_instance().player3->setTurn(true);
            d1.Parse(jsonPlayer3);
            d1["turn"].SetBool(true);
        } else if (d1["id"].GetString() == player3->getId()) {
            Players::shared_instance().player3->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player3->setTurn(false);
            d1.Parse(jsonPlayer3);
            d1["turn"].SetBool(false);
            Players::shared_instance().player4->setTurn(true);
            d1.Parse(jsonPlayer4);
            d1["turn"].SetBool(true);
        } else if (d1["id"].GetString() == player4->getId()) {
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
        cout << "dos" << endl;
        JsonParser jsonParser;
        if (d1["id"].GetString() == player1->getId()) {
            Players::shared_instance().player1->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player1->setTurn(false);
            d1.Parse(jsonPlayer1);
            assert(d1.IsObject());
            StringBuffer buffer1;
            buffer1.Clear();
            Writer<StringBuffer> writer(buffer1);
            d1.Accept(writer);
            char1 = buffer1.GetString();
            buffString1 = buffer1.GetString();
            d1["turn"].SetBool(false);
            d1["matrix"].SetString(getMatrix().data(), getMatrix().size(), d1.GetAllocator());
            d1["letters"].SetString(getLetters().data(), getLetters().size(), d1.GetAllocator());
            d1["score"].SetInt(player1->getScore());
            send(54000, char1, jsonParser.checkJsonSize(buffString1), 0);
            Players::shared_instance().player2->setTurn(true);
            d2.Parse(jsonPlayer2);
            assert(d1.IsObject());
            d2["turn"].SetBool(true);
            d2["matrix"].SetString(getMatrix().data(), getMatrix().size(), d1.GetAllocator());
            d2["score"].SetInt(player2->getScore());
            StringBuffer buffer2;
            buffer2.Clear();
            Writer<StringBuffer> writer2(buffer2);
            d2.Accept(writer2);
            char2 = buffer2.GetString();
            buffString2 = buffer2.GetString();
            send(53000, char2, jsonParser.checkJsonSize(buffString2), 0);
            cout << "buffer1: ";
            cout << char1 << endl;
            cout << "buffer2: ";
            cout << char2 << endl;
        } else if (d1["id"].GetString() == player2->getId()) {
            Players::shared_instance().player1->setScore(d1["score"].GetInt() + hashMap.checkWordScore(d1["letters"].GetString()));
            Players::shared_instance().player1->setTurn(false);
            d1.Parse(jsonPlayer2);
            assert(d1.IsObject());
            StringBuffer buffer1;
            buffer1.Clear();
            Writer<StringBuffer> writer(buffer1);
            d1.Accept(writer);
            buffString1 = buffer1.GetString();
            d1["turn"].SetBool(false);
            d1["matrix"].SetString(getMatrix().data(), getMatrix().size(), d1.GetAllocator());
            d1["letters"].SetString(getLetters().data(), getLetters().size(), d1.GetAllocator());
            d1["score"].SetInt(player2->getScore());
            send(53000, char1, jsonParser.checkJsonSize(buffString1), 0);
            Players::shared_instance().player2->setTurn(true);
            d2.Parse(jsonPlayer1);
            assert(d1.IsObject());
            d2["turn"].SetBool(true);
            d2["matrix"].SetString(getMatrix().data(), getMatrix().size(), d1.GetAllocator());
            d2["score"].SetInt(player1->getScore());
            StringBuffer buffer2;
            buffer2.Clear();
            Writer<StringBuffer> writer2(buffer2);
            d2.Accept(writer2);
            char2 = buffer2.GetString();
            buffString2 = buffer2.GetString();
            send(54000, char2, jsonParser.checkJsonSize(buffString2), 0);
            cout << "buffer1: ";
            cout << char1 << endl;
            cout << "buffer2: ";
            cout << char2 << endl;
        }
    }
}

void Players::setPorts() {

    player1->setPort(54000);
    player2->setPort(53000);
    player3->setPort(54003);
    player4->setPort(54004);

}

int Players::checkTurn() {
    if (player1->isTurn()) {
        cout << "player 1 socket: ";
        cout << player1->getPlayerSocket() << endl;
        return player1->getPlayerSocket();
    } else if (player2->isTurn()) {
        cout << "player 2 socket: ";
        cout << player2->getPlayerSocket() << endl;
        return player2->getPlayerSocket();
    }
}

const string &Players::getMatrix() const {
    return matrix;
}

void Players::setMatrix(const string &matrix) {
    Players::matrix = matrix;
}

const string &Players::getLetters() const {
    return letters;
}

void Players::setLetters(const string &letters) {
    Players::letters = letters;
}

void Players::setPlayerTurns() {
    player1->setTurn(true);
    player2->setTurn(false);
}
