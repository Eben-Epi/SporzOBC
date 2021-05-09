/*!

\file CoreApp.cpp
\brief \sa CoreApp.hpp
\author Eben
\version 0.1

*/

#include "CoreApp/CoreApp.hpp"

CoreApp::CoreApp(int argc, char **argv) {
    initGraphicalHandler(argc, argv);
    this->_graphicalHandler->loadUiView(MAIN_MENU);
    this->_graphicalHandler->changeUiView(MAIN_MENU);
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

void CoreApp::initGraphicalHandler(int argc, char **argv) {
    this->_graphicalHandler = std::make_unique<GraphicalHandler>(*this, argc, argv);
}

std::unique_ptr<IGraphicalHandler> const &CoreApp::getIGraphicalHandlerInstance() {
    if (this->_graphicalHandler)
        return this->_graphicalHandler;
    else
        throw SporzException("GraphicalHandler is not initialized, initGraphicalHandler has not been called or failed", "play");
}

int CoreApp::graphicalHandlerReturnCode() {
    return (static_cast<GraphicalHandler*>(this->_graphicalHandler.get())->appExec());
}
