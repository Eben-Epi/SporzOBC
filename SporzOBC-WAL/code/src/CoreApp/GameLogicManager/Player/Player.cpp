/*!

\file Player.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include "CoreApp/GameLogicManager/Player.hpp"

#include <utility>

Player::Player(std::string username, size_t id) : username(std::move(username)), playerID(id)
{
}

void Player::setUserName(std::string newUserName) {
    this->username = std::move(newUserName);
}

const std::string &Player::getUserName() const {
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

const size_t &Player::getID() const {
    return this->playerID;
}

bool Player::isAlive() {
    return !(this->_state == DEAD);
}

bool Player::isIll() {
    return this->_state == ILL;
}

bool Player::kill() {
    this->_state = DEAD;
    return true;
}

bool Player::paralyze() {
    this->_state = STUNNED;
    return true;
}

bool Player::mutate() {
    if (this->_genome == IMMUNE)
        return false;
    else
        this->_state = ILL;
    return true;
}

bool Player::heal() {
    if (this->_genome == HOST)
        return false;
    else
        this->_state = ALIVE;
    return true;
}
