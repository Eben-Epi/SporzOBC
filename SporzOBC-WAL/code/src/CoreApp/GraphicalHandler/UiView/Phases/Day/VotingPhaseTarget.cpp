/*!

\file VotingPhaseTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Day/ui_voting_phase_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Day/VotingPhaseTarget.hpp"

VotingPhaseTarget::VotingPhaseTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::VotingPhaseTarget), RegisteredInFactory<VotingPhaseTarget>()
{
    ui->setupUi(this);
}

void VotingPhaseTarget::showUi() {
    this->show();
}

VotingPhaseTarget::~VotingPhaseTarget() {
    delete ui;
}

std::unique_ptr<IUiView> VotingPhaseTarget::CreateMethod() {
    return std::make_unique<VotingPhaseTarget>();
}

UiViews VotingPhaseTarget::GetFactoryName() {
    return VOTING_PHASE_TARGET;
}

void VotingPhaseTarget::hideUi() {
    this->hide();
}

void VotingPhaseTarget::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(VOTING_PHASE_END);
    this->accessGH().changeUiView(VOTING_PHASE_END);
}
