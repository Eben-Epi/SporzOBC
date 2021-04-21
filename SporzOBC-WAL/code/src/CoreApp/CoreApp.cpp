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
        throw SporzException("GameLogicManager is not initialized, startNewGame has not been called or failed", "getGameLogicManagerInstance");
}

void CoreApp::startNewGame() {
    this->_gameLogicManager = std::make_unique<GameLogicManager>();
}
