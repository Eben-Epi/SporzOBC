/*!

\file GameLogicManager.cpp
\brief \sa GameLogicManager.hpp
\author Eben
\version 0.1

*/

#include <utility>
#include <algorithm>
#include <random>
#include <chrono>
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
    if (this->playerCount >= id) {
        for (Player& player: this->_players) {
            if (player.getID() == id)
                return player;
        }
    }
    throw GameLogicManagerException("id of player is invalid", funcName, PLAYER_ID_INVALID);
}

void GameLogicManager::randomizeRoles() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    std::shuffle(this->_players.begin(), this->_players.end(), std::default_random_engine(seed));
    for (Player &player : this->_players)
        player.setGenome(STANDARD);
    this->_players[0].setRole(MUTANT);
    this->_players[0].setGenome(HOST);
    this->_players[1].setRole(DOCTOR);
    this->_players[2].setRole(DOCTOR);
    this->_players[3].setRole(COMPUTER_SCIENTIST);
    this->_players[4].setRole(GENETICIST);
    this->_players[5].setRole(PSYCHOLOGIST);
    if (this->playerCount > 6)
        this->_players[6].setRole(HACKER);
    if (this->playerCount > 7)
        this->_players[7].setRole(SPY);
    if (this->playerCount > 8)
        this->_players[8].setRole(NOVICE_HACKER);
    if (this->playerCount > 9)
        this->_players[9].setRole(PAINTER);
}

void GameLogicManager::randomizeGenomes() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->_players.begin(), this->_players.end(), std::default_random_engine(seed));
    bool immuneSet = false;

    for (Player& player : this->_players) {
        if (player.getGenome() == STANDARD) {
            player.setGenome(immuneSet ? HOST : IMMUNE);
            if (immuneSet)
                break;
            immuneSet = true;
        }
    }
}
