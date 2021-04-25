/*!

\file CoreApp.cpp
\brief \sa CoreApp.hpp
\author Eben
\version 0.1

*/

#include "CoreApp/CoreApp.hpp"

CoreApp::CoreApp() {

}

CoreApp::~CoreApp() {

}

std::unique_ptr<GameLogicManager> const &CoreApp::getGameLogicManagerInstance() {
    if (this->_gameLogicManager)
        return this->_gameLogicManager;
    else
        throw SporzException("GameLogicManager is not initialized, initGameLogicManager has not been called or failed", "getGameLogicManagerInstance");
}

void CoreApp::initGameLogicManager() {
    this->_gameLogicManager = std::make_unique<GameLogicManager>();
}

void CoreApp::play() {
    this->initGameLogicManager();
    if (this->_graphicalHandler) {
        this->_graphicalHandler->loadUiGameView(CALCULATOR);
        this->_graphicalHandler->changeUiView(CALCULATOR);
    } else
        throw SporzException("GraphicalHandler is not initialized, initGraphicalHandler has not been called or failed", "play");
}

void CoreApp::initGraphicalHandler() {
    this->_graphicalHandler = std::make_unique<GraphicalHandler>(*this);
}
