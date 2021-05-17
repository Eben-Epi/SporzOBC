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
#include <map>
#include "SporzException/SporzException.hpp"
#include "Player.hpp"
#include "GameHistoryManager.hpp"

#define MIN_PLAYER_SIZE (6)
#define MAX_PLAYER_SIZE (10)

enum GameState {
    BOARDING,
    DAY,
    NIGHT,
    RECAP,
};

enum GameLogicManagerExceptionType {
    RUNTIME_ERROR,
    INCORRECT_NUMBER_OF_PLAYERS,
    PLAYER_NAME_EMPTY,
    PLAYER_ID_INVALID,
    PLAYER_NAME_INVALID,
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
        //! Début de la partie dans le log
        void logCreateGame();

        //! Lancement de la partie
        /*!
         * Lance la partie, si elle a été configurée au préalable par la fonction startGame() ou plus tard //TODO loadGame
         * \sa logCreateGame()
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

        std::vector<const Player*> getAlivePlayers();
        std::vector<const Player*> getAlivePlayersAssociatedWithRole(Role role);
        std::vector<const Player*> getAlivePlayersTargetedByRole(Role role);

        const Player& getAlivePlayerById(size_t ID);
        size_t getAlivePlayerIDByName(const std::string&);

        std::vector<std::string> getPlayerNames();

        void assignChief(size_t id);

        void resetTurns();

        void setTurnPassed(Role);
        bool isTurnPassed(Role);

        void setMutantChoice(ActionType);
        void setMutantsChoiceTarget(size_t);
        void setMutantsParalysisTarget(size_t);
        void setDoctorsChoiceTargets(size_t initiator, size_t target);

        size_t getMutantsChoiceTarget() const;
        size_t getMutantsParalysisTarget() const;
        ActionType getMutantsChoice() const;

        bool killBy(Role);
        std::map<size_t, bool> heals();
        bool mutate();
        bool paralyze();

        void logChiefElection();
        void logMutantAwakening();
        void logMutantChoice();
        void logMutantChoiceTarget();
        void logMutantParalysisTarget();
        std::map<size_t, bool> computeAndLogMutantResult();
    private:
        void resizePlayerVector(size_t size);
        Player& getPlayerInstance(size_t id, const std::string& funcName);
        GameHistoryManager _ghm;

        std::vector<Player> _players;
        size_t playerCount;
        GameState gameState = BOARDING;
        size_t chiefID = 0;
        std::vector<bool> _turns;
        ActionType mutantChoice = NO_ACTION;
        ActionType doctorChoice = NO_ACTION;
        size_t mutantChoiceTarget = 0;
        size_t mutantParalysisTarget = 0;
        std::map<size_t, size_t> doctorTargets;

    };


#endif //SPORZOBC_WAL_GAMELOGICMANAGER_HPP
