/*!

\file NoviceHackerResult.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/NoviceHacker/ui_result.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/NoviceHacker/NoviceHackerResult.hpp"

NoviceHackerResult::NoviceHackerResult(QWidget *parent)
        : QWidget(parent), ui(new Ui::NoviceHackerResult), RegisteredInFactory<NoviceHackerResult>()
{
    ui->setupUi(this);
}

void NoviceHackerResult::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

NoviceHackerResult::~NoviceHackerResult() {
    delete ui;
}

std::unique_ptr<IUiView> NoviceHackerResult::CreateMethod() {
    return std::make_unique<NoviceHackerResult>();
}

UiViews NoviceHackerResult::GetFactoryName() {
    return NOVICE_HACKER_RESULT;
}

void NoviceHackerResult::hideUi() {
    this->hide();
}

void NoviceHackerResult::on_nextNightButton_clicked() {
    this->accessGLM().setTurnPassed(NOVICE_HACKER);
    if (this->accessGLM().getPlayerCount() > 8) {
        this->accessGH().loadUiGameView(SPY_TURN);
        this->accessGH().changeUiView(SPY_TURN);
    } else {
        this->accessGH().loadUiGameView(MORNING_WAKING_UP);
        this->accessGH().changeUiView(MORNING_WAKING_UP);
    }
}
