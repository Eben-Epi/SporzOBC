/*!

\file Player.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include "CoreApp/GameLogicManager/Player/Player.hpp"

#include <utility>

Player::Player(std::string username, size_t id) : username(std::move(username)), playerID(id)
{
}

void Player::setUserName(std::string newUserName) {
    this->username = std::move(newUserName);
}

const std::string &Player::getUserName() {
    return this->username;
}

void Player::setRole(Role role) {
    this->_job = role;
}

const Role &Player::getRole() const {
    return this->_job;
}

void Player::setGenome(Genome genome) {
    this->_genome = genome;
}

const Genome &Player::getGenome() const {
    return this->_genome;
}
