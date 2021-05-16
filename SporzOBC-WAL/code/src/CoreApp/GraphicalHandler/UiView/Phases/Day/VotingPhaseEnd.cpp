/*!

\file VotingPhaseEnd.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Day/ui_voting_phase_end.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Day/VotingPhaseEnd.hpp"

VotingPhaseEnd::VotingPhaseEnd(QWidget *parent)
        : QWidget(parent), ui(new Ui::VotingPhaseEnd), RegisteredInFactory<VotingPhaseEnd>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void VotingPhaseEnd::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

VotingPhaseEnd::~VotingPhaseEnd() {
    delete ui;
}

std::unique_ptr<IUiView> VotingPhaseEnd::CreateMethod() {
    return std::make_unique<VotingPhaseEnd>();
}

UiViews VotingPhaseEnd::GetFactoryName() {
    return VOTING_PHASE_END;
}

void VotingPhaseEnd::hideUi() {
    this->hide();
}

void VotingPhaseEnd::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(VOTING_PHASE_RESULT);
    this->accessGH().changeUiView(VOTING_PHASE_RESULT);
}
