/*!

\file GameUiModel.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_GAMEUIMODEL_HPP
#define SPORZOBC_WAL_GAMEUIMODEL_HPP

#include <CoreApp/GameLogicManager/GameLogicManager.hpp>

class GameUiModel {
public:
    explicit GameUiModel() = default;
    void setGLM(GameLogicManager& glm);
    GameLogicManager &accessGLM();
    ~GameUiModel() = default;
private:
    GameLogicManager *_glm;
};
#endif //SPORZOBC_WAL_GAMEUIMODEL_HPP
