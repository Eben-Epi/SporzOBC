/*!

\file VotingPhaseResult.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Day/ui_voting_phase_result.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Day/VotingPhaseResult.hpp"

VotingPhaseResult::VotingPhaseResult(QWidget *parent)
        : QWidget(parent), ui(new Ui::VotingPhaseResult), RegisteredInFactory<VotingPhaseResult>()
{
    ui->setupUi(this);
}

void VotingPhaseResult::showUi() {
    this->show();
}

VotingPhaseResult::~VotingPhaseResult() {
    delete ui;
}

std::unique_ptr<IUiView> VotingPhaseResult::CreateMethod() {
    return std::make_unique<VotingPhaseResult>();
}

UiViews VotingPhaseResult::GetFactoryName() {
    return VOTING_PHASE_RESULT;
}

void VotingPhaseResult::hideUi() {
    this->hide();
}

void VotingPhaseResult::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(ELIMINATION);
    this->accessGH().changeUiView(ELIMINATION);
}
