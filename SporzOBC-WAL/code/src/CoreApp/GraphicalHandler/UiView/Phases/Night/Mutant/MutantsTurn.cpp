/*!

\file MutantsTurn.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Mutant/ui_turn.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Mutant/MutantsTurn.hpp"

MutantsTurn::MutantsTurn(QWidget *parent)
        : QWidget(parent), ui(new Ui::MutantsTurn), RegisteredInFactory<MutantsTurn>()
{
    ui->setupUi(this);
}

void MutantsTurn::showUi() {
    this->show();
}

MutantsTurn::~MutantsTurn() {
    delete ui;
}

std::unique_ptr<IUiView> MutantsTurn::CreateMethod() {
    return std::make_unique<MutantsTurn>();
}

UiViews MutantsTurn::GetFactoryName() {
    return MUTANTS_TURN;
}

void MutantsTurn::hideUi() {
    this->hide();
}

void MutantsTurn::on_nextButton_clicked() {
    if (!this->accessGLM().isTurnPassed(MUTANT)) {
        this->accessGH().loadUiGameView(MUTANTS_KILL_OR_MUTATE_CHOICE);
        this->accessGH().changeUiView(MUTANTS_KILL_OR_MUTATE_CHOICE);
    } else {
        this->accessGH().loadUiGameView(MUTANTS_RECAP);
        this->accessGH().changeUiView(MUTANTS_RECAP);
    }
}
