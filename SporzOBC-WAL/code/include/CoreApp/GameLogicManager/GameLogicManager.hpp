/*!

\file GameLogicManager.hpp
\brief Orchestrateur de partie et loggeur de game en herbe.
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_GAMELOGICMANAGER_HPP
#define SPORZOBC_WAL_GAMELOGICMANAGER_HPP

#include <utility>
#include <vector>
#include "SporzException/SporzException.hpp"
#include "Player.hpp"

#define MIN_PLAYER_SIZE (6)
#define MAX_PLAYER_SIZE (10)

enum GameState {
    BOARDING,
    DAY,
    NIGHT,
    RECAP
};

enum GameLogicManagerExceptionType {
    RUNTIME_ERROR,
    INCORRECT_NUMBER_OF_PLAYERS,
    PLAYER_NAME_EMPTY,
    PLAYER_ID_INVALID,
    PLAYER_NAME_TOO_LONG
};

class GameLogicManagerException : public SporzException {
public:
    GameLogicManagerException(const std::string& msg, const std::string& funcName, GameLogicManagerExceptionType type = RUNTIME_ERROR)
    : SporzException(msg, funcName, "GameLogicManagerException"), type(type) {}

    GameLogicManagerExceptionType type;
};

//! GameLogicManager
/*!
      Classe représentant l'orchestrateur d'une partie

      Elle agit pour faire dérouler une partie en même
      temps que le MJ. Elle détient les états des joueurs,
      et en fait un "log" pour l'historique de partie.
    */
    class GameLogicManager {
    public:
        GameLogicManager();
        //! Création de la partie
        /*!
         * Instancie le GameLogicManager, généralement après qui l'UI a lancé le signal de création de partie.
         * La partie se crée, le nombre de joueurs présent sont ajustés grâce à la fonction setPlayerCount() et la partie
         * se lancera grâce à la fonction startGame()
         * \sa startGame()
         * \sa setPlayerCount()
         */
        void createGame();

        //! Lancement de la partie
        /*!
         * Lance la partie, si elle a été configurée au préalable par la fonction startGame() ou plus tard //TODO loadGame
         * \sa createGame()
         */
        void startGame();

        //! Nombre de joueurs dans la partie
        /*!
         * \return le nombre de joueurs dans la partie
         */
        [[nodiscard]] const size_t& getPlayerCount() const;

        //! Changer le nombre de joueurs dans la partie
        /*!
         * Crée de nouveaux joueurs en leur assignant un ID et un nom (placeholder). Il faut remplacer ce nom par la suite
         * avec la fonction setPlayerName();
         * \sa setPlayerName();
         */
        void setPlayerCount(size_t);

        //! Changer le nom d'un joueur
        /*!
         * \param id L'ID valide de la cible
         * \param newUserName Nom du joueur, compris entre 1 et 12 caractères
         */
        void setPlayerName(size_t id, std::string newUserName);

        //! Retourne le nom d'un joueur
        /*!
         * \param id L'ID valide de la cible
         * \return le nom du joueur cible
         */
        const std::string &getPlayerName(size_t id);

        //! Changer le role d'un joueur
        /*!
         * \param id L'ID valide de la cible
         * \param newRole Nouveau rôle à assigner
         * \sa Role
         */
        void setPlayerRole(size_t id, Role);

        //! Retourne le role d'un joueur
        /*!
         * \param id L'ID valide de la cible
         * \return le role du joueur cible
         * \sa Role
         */
        [[nodiscard]] const Role& getPlayerRole(size_t id);

        //! Changer le génome d'un joueur
        /*!
         * \param id L'ID valide de la cible
         * \param newGenome Nouveau génome à assigner
         * \sa Genome
         */
        void setPlayerGenome(size_t id, Genome);

        //! Retourne le génome d'un joueur
        /*!
         * \param id L'ID valide de la cible
         * \return le génome du joueur cible
         * \sa Genome
         */
        const Genome& getPlayerGenome(size_t id);

        //! Affectation des rôles des joueurs, en se basant sur une seed aléatoire, conformément à la réparition des rôles
        void randomizeRoles();


        //! Affectation aléatoire des génomes
        void randomizeGenomes();

    private:
        void resetGenomes();
        void resetRoles();
        void setHostMutant();
        void resizePlayerVector(size_t size);
        Player& getPlayerInstance(size_t id, const std::string& funcName);

        std::vector<Player> _players;
        size_t playerCount;
        GameState gameState = BOARDING;
    };


#endif //SPORZOBC_WAL_GAMELOGICMANAGER_HPP
