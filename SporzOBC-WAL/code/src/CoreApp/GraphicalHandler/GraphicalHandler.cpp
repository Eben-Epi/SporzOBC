/*!

\file GraphicalHandler.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <QDebug>
#include <QFontDatabase>
#include <QFile>
#include "CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp"

void GraphicalHandler::changeUiView(UiViews page) {
    if (this->_loadedUiViews.find(page) != this->_loadedUiViews.end()) {
        if (this->currentView != NO_VIEW)
            this->_loadedUiViews[currentView]->hideUi();
        this->_loadedUiViews[page]->showUi();
        this->currentView = page;
    }
}

void GraphicalHandler::loadUiView(UiViews page) {
    if (this->_loadedUiViews.find(page) == this->_loadedUiViews.end())
        this->_loadedUiViews[page] = UiViewFactory::Create(page, this->_coreApp.getIGraphicalHandlerInstance());
    else
        qDebug("This view (%d) is already loaded. Fetch will be handled by cache.", page);
}

void GraphicalHandler::loadUiGameView(UiViews page) {
    if (this->_loadedUiViews.find(page) == this->_loadedUiViews.end()) {
        try {
            this->_coreApp.getGameLogicManagerInstance();
        } catch (SporzException& e) {
            this->_coreApp.initGameLogicManager();
        }
        this->_loadedUiViews[page] = UiViewFactory::Create(page, this->_coreApp.getGameLogicManagerInstance(), this->_coreApp.getIGraphicalHandlerInstance());
    }
    else
        qDebug("This game view (%d) is already loaded. Fetch will be handled by cache.", page);
}

GraphicalHandler::GraphicalHandler(CoreApp &coreApp, int argc, char**argv) : _coreApp(coreApp), currentView(NO_VIEW), _app(argc, argv) {
    QFontDatabase::addApplicationFont(":/fonts/quote");
    QFontDatabase::addApplicationFont(":/fonts/helper");
    QFontDatabase db;

    auto stylesheet = QFile(":/styles/global_app");
    stylesheet.open(QFile::ReadOnly);

    // Apply the loaded stylesheet
    this->globalStyleSheet = (stylesheet.readAll());
}

int GraphicalHandler::appExec() {
   return this->_app.exec();
}

const QString &GraphicalHandler::getGlobalStyleSheet() {
    return (this->globalStyleSheet);
}
