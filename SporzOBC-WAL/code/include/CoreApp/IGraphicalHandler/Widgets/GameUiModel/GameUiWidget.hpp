/*!

\file GameUiModel.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_GAMEUIWIDGET_HPP
#define SPORZOBC_WAL_GAMEUIWIDGET_HPP

#include <CoreApp/GameLogicManager/GameLogicManager.hpp>

class GameUiWidget {
public:
    explicit GameUiWidget() = default;
    void setGLM(GameLogicManager& glm);
    GameLogicManager &accessGLM();
    ~GameUiWidget() = default;
private:
    GameLogicManager *_glm;
};
#endif //SPORZOBC_WAL_GAMEUIWIDGET_HPP
