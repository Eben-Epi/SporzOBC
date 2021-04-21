/*!

\file CoreApp.hpp
\brief Définition de la CoreApp, le point d'entrée de SporzOBC
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_COREAPP_HPP
#define SPORZOBC_WAL_COREAPP_HPP


#include "GameLogicManager/GameLogicManager.hpp"

    //! CoreApp
    /*!
      Classe représentant l'application
      appelée à l'entrée du programme

      Elle sera responsable de faire jouer une game
      et d'en afficher le visuel pour guider le MJ
    */
    class CoreApp {
    public:
        CoreApp();

        ~CoreApp();

        //! Afin d'utiliser le gameLogicManager, on récupère une instance de manière sécurisée
        std::unique_ptr<GameLogicManager> const &getGameLogicManagerInstance();

        //! Initialization du gameLogicManager
        void startNewGame();

    private:
        //! \sa GameLogicManager
        std::unique_ptr<GameLogicManager> _gameLogicManager;
//        _graphicalHandler;
    };


#endif //SPORZOBC_WAL_COREAPP_HPP
