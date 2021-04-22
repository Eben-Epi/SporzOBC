/*!

\file GameLogicManager.cpp
\brief \sa GameLogicManager.hpp
\author Eben
\version 0.1

*/

#include <utility>
#include "CoreApp/GameLogicManager/GameLogicManager.hpp"

GameLogicManager::GameLogicManager() : playerCount(MIN_PLAYER_SIZE) {
    this->resizePlayerVector(this->playerCount);
}

void GameLogicManager::setPlayerCount(size_t number) {
    if (number < MIN_PLAYER_SIZE || number > MAX_PLAYER_SIZE)
        throw GameLogicManagerException("Player number is incorrect, must be between 6 and 12", "GameLogicManagerCTOR", INCORRECT_NUMBER_OF_PLAYERS);
    this->resizePlayerVector(number);
}

const size_t &GameLogicManager::getPlayerCount() const {
    return this->playerCount;
}

void GameLogicManager::createGame() {
    //TODO initialize gameHistoryManager
}

void GameLogicManager::resizePlayerVector(size_t size) {
    if (size > this->_players.size())
        for (size_t current_size = this->_players.size() + 1; current_size != size + 1; current_size++)
            this->_players.emplace_back("Player_Name" + std::to_string(current_size), current_size);
    else if (size < this->_players.size())
        this->_players.resize(size);
    this->playerCount = size;
}

void GameLogicManager::setPlayerName(size_t id, std::string newUserName) {
    if (newUserName.empty())
        throw GameLogicManagerException("name of player is empty", "setPlayerName", PLAYER_NAME_EMPTY);
    else if (newUserName.length() >= 12) {
        throw GameLogicManagerException("name of player is too long", "setPlayerName", PLAYER_NAME_TOO_LONG);
    }
    if (this->playerCount >= id)
        this->_players[id - 1].setUserName(std::move(newUserName));
    else
        throw GameLogicManagerException("id of player is invalid", "setPlayerName", PLAYER_ID_INVALID);
}

void GameLogicManager::startGame() {
    // TODO initialize _turnManager
}

const std::string &GameLogicManager::getPlayerName(size_t id) {
    return this->getPlayerInstance(id, "getPlayerName").getUserName();
}

void GameLogicManager::setPlayerRole(size_t id, Role role) {
    this->getPlayerInstance(id, "setPlayerRole").setRole(role);
}

const Role &GameLogicManager::getPlayerRole(size_t id) {
    return this->getPlayerInstance(id, "getPlayerRole").getRole();
}

void GameLogicManager::setPlayerGenome(size_t id, Genome genome) {
    this->getPlayerInstance(id, "setPlayerGenome").setGenome(genome);
}

const Genome &GameLogicManager::getPlayerGenome(size_t id) {
    return this->getPlayerInstance(id, "getPlayerGenome").getGenome();
}

Player &GameLogicManager::getPlayerInstance(size_t id, const std::string& funcName) {
    if (this->playerCount >= id)
        return this->_players[id - 1];
    else
        throw GameLogicManagerException("id of player is invalid", funcName, PLAYER_ID_INVALID);
}

