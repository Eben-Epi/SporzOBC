/*!

\file HackerResult.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Hacker/ui_result.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Hacker/HackerResult.hpp"

HackerResult::HackerResult(QWidget *parent)
        : QWidget(parent), ui(new Ui::HackerResult), RegisteredInFactory<HackerResult>()
{
    ui->setupUi(this);
}

void HackerResult::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

HackerResult::~HackerResult() {
    delete ui;
}

std::unique_ptr<IUiView> HackerResult::CreateMethod() {
    return std::make_unique<HackerResult>();
}

UiViews HackerResult::GetFactoryName() {
    return HACKER_RESULT;
}

void HackerResult::hideUi() {
    this->hide();
}

void HackerResult::on_nextNightButton_clicked() {
    this->accessGLM().setTurnPassed(HACKER);
    if (this->accessGLM().getPlayerCount() > 7) {
        this->accessGH().loadUiGameView(NOVICE_HACKER_TURN);
        this->accessGH().changeUiView(NOVICE_HACKER_TURN);
    } else {
        this->accessGH().loadUiGameView(MORNING_WAKING_UP);
        this->accessGH().changeUiView(MORNING_WAKING_UP);
    }
}
