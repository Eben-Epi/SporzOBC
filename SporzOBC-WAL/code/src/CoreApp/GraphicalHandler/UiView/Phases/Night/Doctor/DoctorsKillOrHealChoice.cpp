/*!

\file DoctorsKillOrHealChoice.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Doctor/ui_kill_or_heal_choice.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Doctor/DoctorsKillOrHealChoice.hpp"

DoctorsKillOrHealChoice::DoctorsKillOrHealChoice(QWidget *parent)
        : QWidget(parent), ui(new Ui::DoctorsKillOrHealChoice), RegisteredInFactory<DoctorsKillOrHealChoice>()
{
    ui->setupUi(this);
}

void DoctorsKillOrHealChoice::showUi() {
    this->show();
}

DoctorsKillOrHealChoice::~DoctorsKillOrHealChoice() {
    delete ui;
}

std::unique_ptr<IUiView> DoctorsKillOrHealChoice::CreateMethod() {
    return std::make_unique<DoctorsKillOrHealChoice>();
}

UiViews DoctorsKillOrHealChoice::GetFactoryName() {
    return DOCTORS_KILL_OR_HEAL_CHOICE;
}

void DoctorsKillOrHealChoice::hideUi() {
    this->hide();
}

void DoctorsKillOrHealChoice::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(DOCTORS_KILL_OR_HEAL_TARGET);
    this->accessGH().changeUiView(DOCTORS_KILL_OR_HEAL_TARGET);
}
