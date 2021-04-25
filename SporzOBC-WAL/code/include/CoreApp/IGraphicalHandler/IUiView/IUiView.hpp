/*!

\file IUiView.hpp
\brief Interface générique pour une page de l'application
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_IUIVIEW_HPP
#define SPORZOBC_WAL_IUIVIEW_HPP

#include "CoreApp/GameLogicManager/GameLogicManager.hpp"

//! \interface IUiView
class IUiView {
public:
    IUiView() = default;

    virtual ~IUiView() = default;

    virtual void showUi() = 0;
};

class IUiGameView : public IUiView {
public:
    void setGLM(const std::unique_ptr<GameLogicManager>& glm);
protected:
    GameLogicManager *_glm;
};

#endif //SPORZOBC_WAL_IUIVIEW_HPP
