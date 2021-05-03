/*!

\file MutantsKillOrMutateChoice.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Mutant/ui_kill_or_mutate_choice.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Mutant/MutantsKillOrMutateChoice.hpp"

MutantsKillOrMutateChoice::MutantsKillOrMutateChoice(QWidget *parent)
        : QWidget(parent), ui(new Ui::MutantsKillOrMutateChoice), RegisteredInFactory<MutantsKillOrMutateChoice>()
{
    ui->setupUi(this);
}

void MutantsKillOrMutateChoice::showUi() {
    this->show();
}

MutantsKillOrMutateChoice::~MutantsKillOrMutateChoice() {
    delete ui;
}

std::unique_ptr<IUiView> MutantsKillOrMutateChoice::CreateMethod() {
    return std::make_unique<MutantsKillOrMutateChoice>();
}

UiViews MutantsKillOrMutateChoice::GetFactoryName() {
    return MUTANTS_KILL_OR_MUTATE_CHOICE;
}

void MutantsKillOrMutateChoice::hideUi() {
    this->hide();
}

void MutantsKillOrMutateChoice::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(MUTANTS_KILL_OR_MUTATE_TARGET);
    this->accessGH().changeUiView(MUTANTS_KILL_OR_MUTATE_TARGET);
}
