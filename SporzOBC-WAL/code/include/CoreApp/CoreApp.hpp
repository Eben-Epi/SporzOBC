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
        //! Constructeur
        /*! Constructeur de la classe CoreApp */
        CoreApp();

        //! Destructeur
        /*! Destructeur de la classe CoreApp */
        ~CoreApp();

    private:
        GameLogicManager _gameLogicManager;
//        _graphicalHandler;
    };


#endif //SPORZOBC_WAL_COREAPP_HPP
