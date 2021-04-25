/*!

\file CoreApp.hpp
\brief Définition de la CoreApp, le point d'entrée de SporzOBC
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_COREAPP_HPP
#define SPORZOBC_WAL_COREAPP_HPP

class CoreApp;

#include "CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp"
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

        //! Afin d'utiliser le IGraphicalHandler, on récupère une instance de manière sécurisée
        std::unique_ptr<IGraphicalHandler> const &getIGraphicalHandlerInstance();

        //! Initialization du gameLogicManager
        void initGameLogicManager();

        void initGraphicalHandler();

        void MainMenu();

        void play();
    private:
        //! \sa GameLogicManager
        std::unique_ptr<GameLogicManager> _gameLogicManager;
        std::unique_ptr<IGraphicalHandler> _graphicalHandler;
    };


#endif //SPORZOBC_WAL_COREAPP_HPP
