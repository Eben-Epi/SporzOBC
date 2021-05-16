/*!

\file SpyTurn.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Spy/ui_turn.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Spy/SpyTurn.hpp"

SpyTurn::SpyTurn(QWidget *parent)
        : QWidget(parent), ui(new Ui::SpyTurn), RegisteredInFactory<SpyTurn>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void SpyTurn::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

SpyTurn::~SpyTurn() {
    delete ui;
}

std::unique_ptr<IUiView> SpyTurn::CreateMethod() {
    return std::make_unique<SpyTurn>();
}

UiViews SpyTurn::GetFactoryName() {
    return SPY_TURN;
}

void SpyTurn::hideUi() {
    this->hide();
}

void SpyTurn::on_nextNightButton_clicked() {
//    if (!this->accessGLM().isTurnPassed(SPY)) {
    this->accessGH().loadUiGameView(SPY_TARGET);
    this->accessGH().changeUiView(SPY_TARGET);
//    } else
}
