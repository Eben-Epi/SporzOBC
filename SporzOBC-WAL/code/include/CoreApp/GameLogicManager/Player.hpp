/*!

\file Player.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PLAYER_HPP
#define SPORZOBC_WAL_PLAYER_HPP

#include <string>

class Player;

#include "Role.hpp"

class Player {
public:
    explicit Player(std::string username = "PLAYER_NULL", size_t playerID = 0);
    ~Player() = default;

    //! Changement du nom du joueur
    void setUserName(std::string);

    //! Récupérer le nom du joueur
    const std::string& getUserName();

    void setRole(Role);
    [[nodiscard]] const Role& getRole() const;

    void setGenome(Genome);
    [[nodiscard]] const Genome& getGenome() const;

    [[nodiscard]] const size_t& getID() const;
private:
    //! ID du joueur, généralement utilisé pour le cibler
    size_t playerID;

    //! nom public du joueur affiché lors de la partie
    std::string username;

    //! état de santé actuel du joueur.
    /*!
     * \sa PlayerState
     */

    PlayerState _state = ALIVE;

    /*!
     * Compteur d'ancienneté du joueur par rapport au nombre de jours qu'il passe en étant mutant.
     * Déterminant pour la désignation d'un chef des mutants
     */
    int _illCounter = 0;

    //! Profession ou rôle du joueur dans la partie.
    /*!
     * \sa Role
     */
    Role _job = JOBLESS;

    //! Génome du joueur. Ne change pas au cours d'une partie.
    /*!
     * \sa Role
     */
    Genome _genome = STANDARD;

    //! Action qu'a subit le joueur au cours d'une nuit
    /*!
     * \sa ActionType
     */
    std::vector<ActionType> _affected;

    //! ID des joueurs qui ont été en contact avec ce joueur.
    std::vector<size_t> _contacted;
};

#endif //SPORZOBC_WAL_PLAYER_HPP
