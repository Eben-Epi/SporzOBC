/*!

\file PsychologistResult.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Psychologist/ui_result.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Psychologist/PsychologistResult.hpp"

PsychologistResult::PsychologistResult(QWidget *parent)
        : QWidget(parent), ui(new Ui::PsychologistResult), RegisteredInFactory<PsychologistResult>()
{
    ui->setupUi(this);
}

void PsychologistResult::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

PsychologistResult::~PsychologistResult() {
    delete ui;
}

std::unique_ptr<IUiView> PsychologistResult::CreateMethod() {
    return std::make_unique<PsychologistResult>();
}

UiViews PsychologistResult::GetFactoryName() {
    return PSYCHOLOGIST_RESULT;
}

void PsychologistResult::hideUi() {
    this->hide();
}

void PsychologistResult::on_nextButton_clicked() {
    this->accessGLM().setTurnPassed(PSYCHOLOGIST);
    if (this->accessGLM().getPlayerCount() > 6) {
        this->accessGH().loadUiGameView(HACKER_TURN);
        this->accessGH().changeUiView(HACKER_TURN);
    } else {
        this->accessGH().loadUiGameView(MORNING_WAKING_UP);
        this->accessGH().changeUiView(MORNING_WAKING_UP);
    }
}
