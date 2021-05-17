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
#include <ctime>
#include <locale>
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

std::string printableRole(Role role) {
    switch (role) {
        case (MUTANT):
            return "Mutant.e de base";
        case (DOCTOR):
            return "Docteur.e";
        case (COMPUTER_SCIENTIST):
            return "Informaticien.ne";
        case (GENETICIST):
            return "Généticien.ne";
        case (PSYCHOLOGIST):
            return "Psychologue";
        case (HACKER):
            return "Hackeur.se";
        case (NOVICE_HACKER):
            return "Hackeur.se novice";
        case (SPY):
            return "Espion.ne";
        case (PAINTER):
            return "Peintre";
        default:
            throw SporzException("A player was not assigned a correct role", "printableRole");
    }
}

std::string printableGenome(Genome genome) {
    switch (genome) {
        case(STANDARD):
            return "Standard";
        case(IMMUNE):
            return "Résistant";
        case (HOST):
            return "Hôte";
    }
}

void GameLogicManager::resizePlayerVector(size_t size) {
    if (size > this->_players.size()) {
        for (size_t current_size = this->_players.size() + 1; current_size != size + 1; current_size++)
            this->_players.emplace_back("Player_Name" + std::to_string(current_size), current_size);
        this->_turns.resize(size, false);
    }
    else if (size < this->_players.size()) {
        this->_players.resize(size);
        this->_turns.resize(size, false);
    }
    this->playerCount = size;
}

void GameLogicManager::setPlayerName(size_t id, std::string newUserName) {
    if (newUserName.empty())
        throw GameLogicManagerException("name of player is empty", "setPlayerName", PLAYER_NAME_EMPTY);
    else if (newUserName.length() >= 15) {
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
    this->randomizeGenomes();
}

void GameLogicManager::randomizeGenomes() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::shuffle(this->_players.begin(), this->_players.end(), std::default_random_engine(seed));
    bool immuneSet = false;
    for (Player &player : this->_players)
        if (player.getRole() != MUTANT)
            player.setGenome(STANDARD);

    for (Player& player : this->_players) {
        if (player.getGenome() == STANDARD) {
            player.setGenome(immuneSet ? HOST : IMMUNE);
            if (immuneSet)
                break;
            immuneSet = true;
        }
    }
}

std::vector<std::string> GameLogicManager::getPlayerNames() {
    std::vector<std::string> playerNames;
    for (Player& player : this->_players) {
        playerNames.emplace_back(player.getUserName());
    }
    return playerNames;
}

void GameLogicManager::assignChief(size_t id) {
    if (this->playerCount >= id) {
        for (Player& player: this->_players) {
            if (player.getID() == id) {
                this->chiefID = id;
                return;
            }
        }
    }
    throw GameLogicManagerException("id of player is invalid", "assignChief", PLAYER_ID_INVALID);
}

void GameLogicManager::resetTurns() {
    std::fill(_turns.begin(), _turns.end(), false);
}

void GameLogicManager::setTurnPassed(Role role) {
    this->_turns[role] = true;
}

bool GameLogicManager::isTurnPassed(Role role) {
    return this->_turns[role];
}


std::vector<const Player *> GameLogicManager::getAlivePlayers() {
    std::vector<const Player*> targetedPlayers;
    for (Player& player: this->_players) {
        if (player.isAlive())
            targetedPlayers.emplace_back(&player);
    }
    return targetedPlayers;
}

std::vector<const Player*> GameLogicManager::getAlivePlayersAssociatedWithRole(Role roleCalled) {
    std::vector<const Player*> targetedPlayers;

    for (Player& player: this->_players) {
        if (!player.isAlive())
            continue;
        Role pRole = player.getRole();
        if ((roleCalled == MUTANT && (pRole == MUTANT || player.isIll())) || (pRole == roleCalled && !player.isIll() && !player.isParalyzed()))
            targetedPlayers.emplace_back(&player);
    }
    return targetedPlayers;
}

std::vector<const Player*> GameLogicManager::getAlivePlayersTargetedByRole(Role roleCalled) {
    std::vector<const Player*> targetedPlayers;

    for (Player& player: this->_players) {
        if (!player.isAlive())
            continue;
        Role pRole = player.getRole();
        switch (roleCalled) {
            case HACKER:
            case NOVICE_HACKER:
                if (pRole == PSYCHOLOGIST || pRole == GENETICIST || pRole == COMPUTER_SCIENTIST)
                    targetedPlayers.emplace_back(&player);
                break;
            case MUTANT:
                if (pRole != MUTANT && !player.isIll())
                    targetedPlayers.emplace_back(&player);
                break;
            default:
                if (pRole != roleCalled || (pRole == roleCalled && player.isIll()))
                    targetedPlayers.emplace_back(&player);
                break;
        }
    }
    return targetedPlayers;
}

const Player &GameLogicManager::getAlivePlayerById(size_t ID) {
    if (this->playerCount >= ID) {
        for (Player& player: this->_players) {
            if (player.getID() == ID && player.isAlive()) {
                return player;
            }
        }
    }
    throw GameLogicManagerException("id of player is invalid or player is dead", "getAlivePlayerById", PLAYER_ID_INVALID);
}

size_t GameLogicManager::getAlivePlayerIDByName(const std::string &nameToFind) {
    for (Player& player: this->_players) {
        if (player.getUserName() == nameToFind && player.isAlive()) {
            return player.getID();
        }
    }
    throw GameLogicManagerException("cannot find alive player with name " + nameToFind, "getAlivePlayerIDByName", PLAYER_NAME_INVALID);
}

void GameLogicManager::setMutantChoice(ActionType actionType) {
    if (actionType == MUTATION || actionType == KILLING) {
        this->mutantChoice = actionType;
    } else {
        throw GameLogicManagerException("Wrong action type choice for mutants : they can only choose to kill or mutate target", "setMutantChoice");
    }
}

bool GameLogicManager::killBy(Role role) {
    bool result = false;

    if (role == MUTANT) {
        result = this->getPlayerInstance(this->mutantChoiceTarget, "kill").kill();
    } else if (role == DOCTOR) {
        result = this->getPlayerInstance(this->doctorTargets[0], "kill").kill();
    }
    return result;
}

bool GameLogicManager::mutate() {
    bool result = this->getPlayerInstance(this->mutantChoiceTarget, "mutate").mutate();
    return result;
}

bool GameLogicManager::paralyze() {
    bool result = this->getPlayerInstance(this->mutantParalysisTarget, "paralyze").paralyze();
    return result;
}

std::map<size_t, bool> GameLogicManager::heals() {
    auto aliveDoctors = getAlivePlayersAssociatedWithRole(DOCTOR);
    std::map<size_t, bool> heals;

    for (auto &doctor : aliveDoctors)
        heals[doctor->getID()] = this->getPlayerInstance(this->doctorTargets[doctor->getID()], "heals").heal();
    return heals;
}

void GameLogicManager::setDoctorsChoiceTargets(size_t initiator, size_t target) {
    this->doctorTargets[initiator] = target;
}

void GameLogicManager::setMutantsChoiceTarget(size_t ID) {
    this->mutantChoiceTarget = ID;
}

void GameLogicManager::setMutantsParalysisTarget(size_t ID) {
    this->mutantParalysisTarget = ID;
}

size_t GameLogicManager::getMutantsChoiceTarget() const {
    return this->mutantChoiceTarget;
}

size_t GameLogicManager::getMutantsParalysisTarget() const {
    return this->mutantParalysisTarget;
}

ActionType GameLogicManager::getMutantsChoice() const {
    return this->mutantChoice;
}

void GameLogicManager::logCreateGame() {
    std::time_t t = std::time(nullptr);
    char mbstr[100];
    if (std::strftime(mbstr, sizeof(mbstr), "%A %c", std::localtime(&t))) {
        this->_ghm.out() << "\n**********\n Nouvelle Partie - ";
        this->_ghm.out() << mbstr << '\n';
        this->_ghm.out() << "**********\n";
    } else {
        this->_ghm.out() << "\n**********\n Nouvelle Partie \n**********\n";
    }

    this->_ghm.out() << "Il y a " << this->getPlayerCount() << " joueurs dans la partie :\n";
    for (auto player : this->_players) {
        this->_ghm.out() << "- " << player.getUserName().c_str() << " est " << printableRole(player.getRole()).c_str() << " de génome " <<  printableGenome(player.getGenome()).c_str() <<".\n";
    }
    this->logChiefElection();
    this->_ghm.out() << "\n****\n Début de partie \n****\n\n";
}

void GameLogicManager::logChiefElection() {
    this->_ghm.out() << "Le.La chef.fe élu.e est " << this->getPlayerName(this->chiefID).c_str() << ".\n";
}

void GameLogicManager::logMutantAwakening() {
    auto aliveMutants = this->getAlivePlayersAssociatedWithRole(MUTANT);
    this->_ghm.out() << "**\n Tour des Mutant.e.s\n**\n\n";
    this->_ghm.out() << "Réveil des mutant.e.s en vie (";
    for (auto it = aliveMutants.begin(); it != aliveMutants.end() ; it++)
        this->_ghm.out() << it.operator*()->getUserName().c_str() << (std::next(it) == aliveMutants.end() ? ").\n" : ", ");
}

void GameLogicManager::logMutantChoice() {
    this->_ghm.out() << "La décision prise est de " << (this->mutantChoice == KILLING ? "tuer " : "muter ");
}

void GameLogicManager::logMutantChoiceTarget() {
    this->_ghm.out() << this->getPlayerName(this->mutantChoiceTarget).c_str() << ".\n";
}

void GameLogicManager::logMutantParalysisTarget() {
    this->_ghm.out() << "La cible de la paralysie sera " << this->getPlayerName(this->mutantParalysisTarget).c_str() << ".\n";
}

std::map<size_t, bool> GameLogicManager::computeAndLogMutantResult() {
    std::map<size_t, bool> results;
    results[this->mutantChoiceTarget] = this->mutantChoice == KILLING ? this->killBy(MUTANT) : this->mutate();
    results[this->mutantParalysisTarget] = this->paralyze();
    if (results[this->mutantChoiceTarget]) {
        this->_ghm.out()    << "La cible "
                            << (this->mutantChoice == KILLING ? "du meurtre (" : "de la mutation (")
                            << this->getPlayerName(this->mutantChoiceTarget).c_str() << ") est "
                            << (this->mutantChoice == KILLING ? "décédée.\n" : "mutée.\n");
    } else {
        this->_ghm.out()    << "La cible de la mutation ("
                            << this->getPlayerName(this->mutantChoiceTarget).c_str()
                            << ") a résisté.\n";
    }
    this->_ghm.out() << "La cible de la paralysie (" << this->getPlayerName(this->mutantParalysisTarget).c_str() << ") est paralysée.\n";
    this->_ghm.out() << "**\n Fin du tour des Mutant.e.s\n**\n\n";
    return results;
}
