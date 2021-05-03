/*!

\file PsychologistTurn.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Psychologist/ui_turn.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Psychologist/PsychologistTurn.hpp"

PsychologistTurn::PsychologistTurn(QWidget *parent)
        : QWidget(parent), ui(new Ui::PsychologistTurn), RegisteredInFactory<PsychologistTurn>()
{
    ui->setupUi(this);
}

void PsychologistTurn::showUi() {
    this->show();
}

PsychologistTurn::~PsychologistTurn() {
    delete ui;
}

std::unique_ptr<IUiView> PsychologistTurn::CreateMethod() {
    return std::make_unique<PsychologistTurn>();
}

UiViews PsychologistTurn::GetFactoryName() {
    return PSYCHOLOGIST_TURN;
}

void PsychologistTurn::hideUi() {
    this->hide();
}

void PsychologistTurn::on_nextButton_clicked() {
    if (!this->accessGLM().isTurnPassed(PSYCHOLOGIST)) {
        this->accessGH().loadUiGameView(PSYCHOLOGIST_TARGET);
        this->accessGH().changeUiView(PSYCHOLOGIST_TARGET);
    } else if (this->accessGLM().getPlayerCount() > 6) {
        this->accessGH().loadUiGameView(HACKER_TURN);
        this->accessGH().changeUiView(HACKER_TURN);
    } else {
        this->accessGH().loadUiGameView(MORNING_WAKING_UP);
        this->accessGH().changeUiView(MORNING_WAKING_UP);
    }
}
