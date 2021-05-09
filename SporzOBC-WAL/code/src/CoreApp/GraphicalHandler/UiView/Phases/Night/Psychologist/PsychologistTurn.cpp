/*!

\file PsychologistTurn.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Psychologist/ui_turn.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Psychologist/PsychologistTurn.hpp"

PsychologistTurn::PsychologistTurn(QWidget *parent)
        : QWidget(parent), ui(new Ui::PsychologistTurn), RegisteredInFactory<PsychologistTurn>()
{
    ui->setupUi(this);
}

void PsychologistTurn::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
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
//    if (!this->accessGLM().isTurnPassed(PSYCHOLOGIST)) {
        this->accessGH().loadUiGameView(PSYCHOLOGIST_TARGET);
        this->accessGH().changeUiView(PSYCHOLOGIST_TARGET);
}
