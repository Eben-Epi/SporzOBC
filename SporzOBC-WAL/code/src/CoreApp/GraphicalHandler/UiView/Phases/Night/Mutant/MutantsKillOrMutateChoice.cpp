/*!

\file MutantsKillOrMutateChoice.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Mutant/ui_kill_or_mutate_choice.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Mutant/MutantsKillOrMutateChoice.hpp"

MutantsKillOrMutateChoice::MutantsKillOrMutateChoice(QWidget *parent)
        : QWidget(parent), ui(new Ui::MutantsKillOrMutateChoice), RegisteredInFactory<MutantsKillOrMutateChoice>()
{
    ui->setupUi(this);
}

void MutantsKillOrMutateChoice::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->ui->nextButton->setDisabled(true);
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

void MutantsKillOrMutateChoice::on_nextNightButton_clicked() {
    this->accessGH().loadUiGameView(MUTANTS_KILL_OR_MUTATE_TARGET);
    this->accessGH().changeUiView(MUTANTS_KILL_OR_MUTATE_TARGET);
}

void MutantsKillOrMutateChoice::on_choice_buttonToggled(QAbstractButton *button, bool checked) {
    if (checked) {
        if (button == this->ui->killChoice)
            this->accessGLM().setMutantChoice(KILLING);
        } else if (button == this->ui->mutateChoice) {
            this->accessGLM().setMutantChoice(MUTATION);
    }
    this->ui->nextButton->setEnabled(true);
}
