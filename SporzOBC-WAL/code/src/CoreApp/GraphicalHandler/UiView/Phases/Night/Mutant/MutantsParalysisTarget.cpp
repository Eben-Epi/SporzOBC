/*!

\file MutantsParalysisTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Mutant/ui_paralysis_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Mutant/MutantsParalysisTarget.hpp"

MutantsParalysisTarget::MutantsParalysisTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::MutantsParalysisTarget), RegisteredInFactory<MutantsParalysisTarget>()
{
    ui->setupUi(this);
}

void MutantsParalysisTarget::showUi() {
    this->show();
}

MutantsParalysisTarget::~MutantsParalysisTarget() {
    delete ui;
}

std::unique_ptr<IUiView> MutantsParalysisTarget::CreateMethod() {
    return std::make_unique<MutantsParalysisTarget>();
}

UiViews MutantsParalysisTarget::GetFactoryName() {
    return MUTANT_PARALYSIS_TARGET;
}

void MutantsParalysisTarget::hideUi() {
    this->hide();
}

void MutantsParalysisTarget::on_nextButton_clicked() {
    this->accessGLM().setTurnPassed(MUTANT);
    this->accessGH().loadUiGameView(MUTANTS_TURN);
    this->accessGH().changeUiView(MUTANTS_TURN);
}
