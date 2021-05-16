/*!

\file GraphicalHandler.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <QDebug>
#include <QFontDatabase>
#include <QScreen>
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

//    qreal refDpi = 96.;
//    qreal refHeight = 1280.;
//    qreal refWidth = 720.;
//    auto rect = this->_app.primaryScreen()->geometry();
//    qreal height = rect.height();
//    qreal width = rect.width();
//    qreal ldpi = this->_app.primaryScreen()->logicalDotsPerInch();
//    qreal pdpi = this->_app.primaryScreen()->physicalDotsPerInch();
//    auto m_ratio = qMin(height/refHeight, width/refWidth);
//    auto m_ratioFont = qMin(height*refDpi/(dpi*refHeight), width*refDpi/(dpi*refWidth));

    auto stylesheet = QFile(":/styles/global_app");
//    double dpi_factor = this->_app.devicePixelRatio();
    stylesheet.open(QFile::ReadOnly);

//
//    QString styleSheetText = QString::fromUtf8("width : %1, height : %2, ldpi : %3, pdpi : %4").arg(width).arg(height).arg(ldpi).arg(pdpi);
//    QString styleSheetText = QString::fromUtf8(stylesheet.readAll()).arg(floor(dpi)).arg(floor(dpi));
//    qDebug().noquote() << styleSheetText;
    // Apply the loaded stylesheet
    this->globalStyleSheet = stylesheet.readAll();
}

int GraphicalHandler::appExec() {
   return this->_app.exec();
}

const QString &GraphicalHandler::getGlobalStyleSheet() {
    return (this->globalStyleSheet);
}
