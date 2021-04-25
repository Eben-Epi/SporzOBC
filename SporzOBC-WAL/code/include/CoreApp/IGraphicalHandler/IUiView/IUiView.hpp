/*!

\file IUiView.hpp
\brief Interface générique pour une page de l'application
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_IUIVIEW_HPP
#define SPORZOBC_WAL_IUIVIEW_HPP

class IUiView;

#include <memory>
#include <CoreApp/IGraphicalHandler/IGraphicalHandler.hpp>
#include "CoreApp/GameLogicManager/GameLogicManager.hpp"

//! \interface IUiView
class IUiView {
public:
    virtual ~IUiView() = default;

    virtual void showUi() = 0;
    virtual void hideUi() = 0;
    void setGH(const std::unique_ptr<IGraphicalHandler>& gh) {
        this->_gh = gh.get();
    };
    IGraphicalHandler &accessGH() {
        if(this->_gh != nullptr)
            return *this->_gh;
        throw SporzException("IGraphicalHandler is not initialized", "accessGH");

    };

private:
    IGraphicalHandler *_gh = nullptr;
};

class UiGameView : public IUiView {
public:
    void setGLM(const std::unique_ptr<GameLogicManager>& glm);
    GameLogicManager &accessGLM();
private:
    GameLogicManager *_glm = nullptr;
};

#endif //SPORZOBC_WAL_IUIVIEW_HPP
