/*!

\file MutantsRecap.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Mutant/ui_recap.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Mutant/MutantsRecap.hpp"

MutantsRecap::MutantsRecap(QWidget *parent)
        : QWidget(parent), ui(new Ui::MutantsRecap), RegisteredInFactory<MutantsRecap>()
{
    ui->setupUi(this);
}

void MutantsRecap::showUi() {
    this->show();
}

MutantsRecap::~MutantsRecap() {
    delete ui;
}

std::unique_ptr<IUiView> MutantsRecap::CreateMethod() {
    return std::make_unique<MutantsRecap>();
}

UiViews MutantsRecap::GetFactoryName() {
    return MUTANTS_RECAP;
}

void MutantsRecap::hideUi() {
    this->hide();
}

void MutantsRecap::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(DOCTORS_TURN);
    this->accessGH().changeUiView(DOCTORS_TURN);
}
