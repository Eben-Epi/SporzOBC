/*!

\file NoviceHackerTurn.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/NoviceHacker/ui_turn.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/NoviceHacker/NoviceHackerTurn.hpp"

NoviceHackerTurn::NoviceHackerTurn(QWidget *parent)
        : QWidget(parent), ui(new Ui::NoviceHackerTurn), RegisteredInFactory<NoviceHackerTurn>()
{
    ui->setupUi(this);
}

void NoviceHackerTurn::showUi() {
    this->show();
}

NoviceHackerTurn::~NoviceHackerTurn() {
    delete ui;
}

std::unique_ptr<IUiView> NoviceHackerTurn::CreateMethod() {
    return std::make_unique<NoviceHackerTurn>();
}

UiViews NoviceHackerTurn::GetFactoryName() {
    return NOVICE_HACKER_TURN;
}

void NoviceHackerTurn::hideUi() {
    this->hide();
}

void NoviceHackerTurn::on_nextButton_clicked() {
//    if (!this->accessGLM().isTurnPassed(NOVICE_HACKER)) {
    this->accessGH().loadUiGameView(NOVICE_HACKER_TARGET);
    this->accessGH().changeUiView(NOVICE_HACKER_TARGET);
//    } else
}
