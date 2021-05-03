/*!

\file MutantsKillOrMutateTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Mutant/ui_kill_or_mutate_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Mutant/MutantsKillOrMutateTarget.hpp"

MutantsKillOrMutateTarget::MutantsKillOrMutateTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::MutantsKillOrMutateTarget), RegisteredInFactory<MutantsKillOrMutateTarget>()
{
    ui->setupUi(this);
}

void MutantsKillOrMutateTarget::showUi() {
    this->show();
}

MutantsKillOrMutateTarget::~MutantsKillOrMutateTarget() {
    delete ui;
}

std::unique_ptr<IUiView> MutantsKillOrMutateTarget::CreateMethod() {
    return std::make_unique<MutantsKillOrMutateTarget>();
}

UiViews MutantsKillOrMutateTarget::GetFactoryName() {
    return MUTANTS_KILL_OR_MUTATE_TARGET;
}

void MutantsKillOrMutateTarget::hideUi() {
    this->hide();
}

void MutantsKillOrMutateTarget::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(MUTANT_PARALYSIS_TARGET);
    this->accessGH().changeUiView(MUTANT_PARALYSIS_TARGET);
}
