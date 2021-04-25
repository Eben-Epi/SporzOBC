/*!

\file GraphicalHandler.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_GRAPHICALHANDLER_HPP
#define SPORZOBC_WAL_GRAPHICALHANDLER_HPP

class GraphicalHandler;

#include "CoreApp/IGraphicalHandler/IGraphicalHandler.hpp"
#include "CoreApp/CoreApp.hpp"

class GraphicalHandler : public IGraphicalHandler {
public:
    explicit GraphicalHandler(CoreApp& coreApp) : _coreApp(coreApp), currentView(NO_VIEW) {}
    void changeUiView(UiViews page) override;
    void loadUiGameView(UiViews page) override;
    void loadUiView(UiViews page) override;
private:
    CoreApp &_coreApp;
    std::map<UiViews, std::unique_ptr<IUiView>> _loadedUiViews;
    UiViews currentView;
};

#endif //SPORZOBC_WAL_GRAPHICALHANDLER_HPP
