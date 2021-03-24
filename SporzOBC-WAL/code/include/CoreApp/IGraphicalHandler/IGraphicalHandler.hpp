/*!

\file IGraphicalHandler.hpp
\brief Interface pour la librairie graphique utilisée par SporzOBC
\author Eben
\version 0.1

*/


#ifndef SPORZOBC_WAL_IGRAPHICALHANDLER_HPP
#define SPORZOBC_WAL_IGRAPHICALHANDLER_HPP

#include <memory>

//! \interface IGraphicalHandler
/*!
  Interface servant à implémenter une Ui avec la lib
  graphique de son choix

  Doit implémenter un système de pages (IUiViews) pour faire défiler
  le jeu.
*/
    class IGraphicalHandler {
    public:
        //! Destructeur
        /*! Destructeur virtuel de la classe IGraphicalHandler */
        virtual ~IGraphicalHandler() = default;

        //! Changement de page
        /*! Change la page actuellement affichée. Une UiView
         *  est l'affichage correspondant à l'interface
         *  utilisateur actuellement affichée à l'écran
         *
         *  \param page L'id d'une page actuellement chargée dans
         *  le GraphicalHandler. Pour charger une page en cache
         *  dans celui-ci, se référer à la fonction loadUiView()
         *  \sa IGraphicalHandler::loadUiView() */
        virtual void changeUiView(size_t page) = 0;

        //! Chargement de page
        /*! Charge une nouvelle page grâce à la factory \sa UiViewFactory
         *
         *
         *  \param page L'id d'une page valide dans la factory UiViewFactory.
         *  Pour utiliser une page après sa création,
         *  se référer à la fonction \sa IGraphicalHandler::loadUiView() */
        virtual void loadUiView(size_t page) = 0;
    };

#endif //SPORZOBC_WAL_IGRAPHICALHANDLER_HPP
