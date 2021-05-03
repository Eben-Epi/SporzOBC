/*!

\file HackerTurn.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Hacker/ui_turn.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Hacker/HackerTurn.hpp"

HackerTurn::HackerTurn(QWidget *parent)
        : QWidget(parent), ui(new Ui::HackerTurn), RegisteredInFactory<HackerTurn>()
{
    ui->setupUi(this);
}

void HackerTurn::showUi() {
    this->show();
}

HackerTurn::~HackerTurn() {
    delete ui;
}

std::unique_ptr<IUiView> HackerTurn::CreateMethod() {
    return std::make_unique<HackerTurn>();
}

UiViews HackerTurn::GetFactoryName() {
    return HACKER_TURN;
}

void HackerTurn::hideUi() {
    this->hide();
}

void HackerTurn::on_nextButton_clicked() {
    if (!this->accessGLM().isTurnPassed(HACKER)) {
        this->accessGH().loadUiGameView(HACKER_TARGET);
        this->accessGH().changeUiView(HACKER_TARGET);
    } else if (this->accessGLM().getPlayerCount() > 7) {
        this->accessGH().loadUiGameView(NOVICE_HACKER_TURN);
        this->accessGH().changeUiView(NOVICE_HACKER_TURN);
    } else {
        this->accessGH().loadUiGameView(MORNING_WAKING_UP);
        this->accessGH().changeUiView(MORNING_WAKING_UP);
    }
}
