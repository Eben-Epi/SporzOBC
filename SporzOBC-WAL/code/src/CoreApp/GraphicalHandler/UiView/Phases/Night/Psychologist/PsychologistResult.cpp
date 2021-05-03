/*!

\file PsychologistResult.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Psychologist/ui_result.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Psychologist/PsychologistResult.hpp"

PsychologistResult::PsychologistResult(QWidget *parent)
        : QWidget(parent), ui(new Ui::PsychologistResult), RegisteredInFactory<PsychologistResult>()
{
    ui->setupUi(this);
}

void PsychologistResult::showUi() {
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
    this->accessGH().loadUiGameView(PSYCHOLOGIST_TURN);
    this->accessGH().changeUiView(PSYCHOLOGIST_TURN);
}
