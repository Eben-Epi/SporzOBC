/*!

\file IUiGameView.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include "CoreApp/IGraphicalHandler/IUiView/IUiView.hpp"

void IUiGameView::setGLM(const std::unique_ptr<GameLogicManager>& glm) {
    this->_glm = glm.get();
}