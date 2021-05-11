/*!

\file DoctorsKillOrHealTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Doctor/ui_kill_or_heal_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Doctor/DoctorsKillOrHealTarget.hpp"

DoctorsKillOrHealTarget::DoctorsKillOrHealTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::DoctorsKillOrHealTarget), RegisteredInFactory<DoctorsKillOrHealTarget>()
{
    ui->setupUi(this);
}

void DoctorsKillOrHealTarget::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

DoctorsKillOrHealTarget::~DoctorsKillOrHealTarget() {
    delete ui;
}

std::unique_ptr<IUiView> DoctorsKillOrHealTarget::CreateMethod() {
    return std::make_unique<DoctorsKillOrHealTarget>();
}

UiViews DoctorsKillOrHealTarget::GetFactoryName() {
    return DOCTORS_KILL_OR_HEAL_TARGET;
}

void DoctorsKillOrHealTarget::hideUi() {
    this->hide();
}

void DoctorsKillOrHealTarget::on_nextNightButton_clicked() {
    this->accessGLM().setTurnPassed(DOCTOR);
    this->accessGH().loadUiGameView(DOCTORS_RECAP);
    this->accessGH().changeUiView(DOCTORS_RECAP);
}
