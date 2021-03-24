/*!

\file GameLogicManager.hpp
\brief Orchestrateur de partie et loggeur de game en herbe.
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_GAMELOGICMANAGER_HPP
#define SPORZOBC_WAL_GAMELOGICMANAGER_HPP

    //! GameLogicManager
    /*!
      Classe représentant l'orchestrateur d'une partie

      Elle agit pour faire dérouler une partie en même
      temps que le MJ. Elle détient les états des joueurs,
      et en fait un "log" pour l'historique de partie.
    */
    class GameLogicManager {
    public:
        //! Constructeur
        /*! Constructeur de la classe GameLogicManager */
        GameLogicManager();

        //! Destructeur
        /*! Destructeur de la classe GameLogicManager */
        ~GameLogicManager();
    };


#endif //SPORZOBC_WAL_GAMELOGICMANAGER_HPP
