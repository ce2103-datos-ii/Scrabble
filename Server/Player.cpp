//
// Created by ivan on 3/24/19.
//

#include "Player.h"
#include "Players.h"

const char *Player::getTiles() const {
    return tiles;
}

int Player::getScore() const {
    return score;
}

void Player::setScore(int score) {
//    Document d;
//    const char* jsonChar = json.c_str();
//    d.Parse(jsonChar);
//    cout << "json: ";
//    cout << json << endl;
//    assert(d.IsObject());
//    d["score"].SetInt(score);
//    StringBuffer buffer;
//    buffer.Clear();
//    Writer<StringBuffer> writer(buffer);
//    d.Accept(writer);
//    Players::shared_instance().checkTurnInstance()->setJson(buffer.GetString());
    Player::score = score;
}

bool Player::isTurn() const {
    return turn;
}

void Player::setTurn(bool turn) {
    Player::turn = turn;
}

Player::~Player() {

}

void Player::setId(const string &id) {
    Player::id = id;
}

const string &Player::getId() const {
    return id;
}

int Player::getPort() const {
    return port;
}

void Player::setPort(int port) {
    Player::port = port;
}

int Player::getPlayerSocket() const {
    return playerSocket;
}

void Player::setPlayerSocket(int playerSocket) {
    Player::playerSocket = playerSocket;
}

const char* Player::getJson() const {
    return json;
}

//void Player::setJson(const char *json) {
//    Player::json = json;
//}

const string &Player::getLetters() const {
    return letters;
}

void Player::setLetters(const string &letters) {
//    Document d;
//    const char* jsonChar = json.c_str();
//    d.Parse(jsonChar);
//    assert(d.IsObject());
//    d["letters"].SetString(letters.data(), letters.size(), d.GetAllocator());
//    StringBuffer buffer;
//    buffer.Clear();
//    Writer<StringBuffer> writer(buffer);
//    d.Accept(writer);
//    cout << "buffer.GetString setLetters: ";
//    cout << buffer.GetString() << endl;
//    cout << "json setLetters:";
//    cout << getJson() << endl;
//    Players::shared_instance().checkTurnInstance()->setJson(buffer.GetString());
//    cout << "json setLetters:";
//    cout << getJson() << endl;
    Player::letters = letters;
}
