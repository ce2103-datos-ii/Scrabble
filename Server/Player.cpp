//
// Created by ivan on 3/24/19.
//

#include "Player.h"

const char *Player::getTiles() const {
    return tiles;
}

int Player::getScore() const {
    return score;
}

void Player::setScore(int score) {
    Player::score = score;
}

bool Player::isTurn() const {
    return turn;
}

void Player::setTurn(bool turn) {
    Player::turn = turn;
}

int Player::getId() const {
    return id;
}
