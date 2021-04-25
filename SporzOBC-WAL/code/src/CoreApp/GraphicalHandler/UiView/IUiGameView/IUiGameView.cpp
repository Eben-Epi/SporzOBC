/*!

\file IUiGameView.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include "CoreApp/IGraphicalHandler/IUiView/IUiView.hpp"

void UiGameView::setGLM(const std::unique_ptr<GameLogicManager>& glm) {
    this->_glm = glm.get();
}

GameLogicManager &UiGameView::accessGLM() {
    if(this->_glm != nullptr)
        return *this->_glm;
    throw SporzException(" Either GameLogicManager is not initialized or this GameUiView has not been created by the right factory Create()", "accessGLM");
}