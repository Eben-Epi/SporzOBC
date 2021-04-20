/*!

\file Player.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PLAYER_HPP
#define SPORZOBC_WAL_PLAYER_HPP

#include <string>
#include <CoreApp/GameLogicManager/Role/Role.hpp>

class Player {
    Player() =  default;
    ~Player() = default;

private:
    std::string username;
    PlayerState _state;
    int _mutated_counter;
    Role _job;
    Genome _genome;
};

#endif //SPORZOBC_WAL_PLAYER_HPP
