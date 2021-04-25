/*!

\file GameUiModel.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include "CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiModel.hpp"

void GameUiModel::setGLM(GameLogicManager &glm) {
    this->_glm = &glm;
}

GameLogicManager &GameUiModel::accessGLM() {
    if(this->_glm != nullptr)
        return *this->_glm;
    throw SporzException(" Either GameLogicManager is not initialized or this GameUiView has not been created by the right factory Create()", "accessGLM");

}