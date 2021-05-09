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
#include <QApplication>

class GraphicalHandler : public IGraphicalHandler {
public:
    explicit GraphicalHandler(CoreApp& coreApp, int argc, char**argv);
    void changeUiView(UiViews page) override;
    void loadUiGameView(UiViews page) override;
    void loadUiView(UiViews page) override;
    const QString &getGlobalStyleSheet();
    int appExec();
private:
    QApplication _app;
    QString globalStyleSheet;
    CoreApp &_coreApp;
    std::map<UiViews, std::unique_ptr<IUiView>> _loadedUiViews;
    UiViews currentView;
};

#endif //SPORZOBC_WAL_GRAPHICALHANDLER_HPP
