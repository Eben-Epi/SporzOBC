/*!

\file GraphicalHandler.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <QDebug>
#include "CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp"

void GraphicalHandler::changeUiView(UiViews page) {
    if (this->_loadedUiViews.find(page) != this->_loadedUiViews.end()) {
        if (this->currentView != NO_VIEW)
            this->_loadedUiViews[currentView]->hideUi();
        this->_loadedUiViews[page]->showUi();
        this->currentView = page;
    }
}

void GraphicalHandler::loadUiView(UiViews page) {
    if (this->_loadedUiViews.find(page) == this->_loadedUiViews.end())
        this->_loadedUiViews[page] = UiViewFactory::Create(page);
    else
        qDebug("This view (%d) is already loaded. Fetch will be handled by cache.", page);
}

void GraphicalHandler::loadUiGameView(UiViews page) {
    if (this->_loadedUiViews.find(page) == this->_loadedUiViews.end())
        this->_loadedUiViews[page] = UiViewFactory::Create(page, this->_coreApp.getGameLogicManagerInstance());
    else
        qDebug("This game view (%d) is already loaded. Fetch will be handled by cache.", page);
}
