/*!

\file DoctorsTurn.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Doctor/ui_turn.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Doctor/DoctorsTurn.hpp"

DoctorsTurn::DoctorsTurn(QWidget *parent)
        : QWidget(parent), ui(new Ui::DoctorsTurn), RegisteredInFactory<DoctorsTurn>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void DoctorsTurn::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    auto aliveDoctors = this->accessGLM().getAlivePlayersAssociatedWithRole(DOCTOR);
    std::string labelText;
    if (aliveDoctors.size() > 1 && this->accessGLM().isTurnPassed(MUTANT)) {
        labelText += "Les docteurs en vie sont : ";
        for (auto player = aliveDoctors.begin(); player != aliveDoctors.end(); ++player) {
            if (player != aliveDoctors.begin())
                labelText += (std::next(player) == aliveDoctors.end() ? " et " : ", ") + player.operator*()->getUserName();
            else
                labelText += player.operator*()->getUserName();
        }
        labelText += ".";
    } else
        labelText += "Le mutant de base nommé " + aliveDoctors[0]->getUserName() + " se réveille.";
    this->ui->aliveDoctors->setText(labelText.c_str());
    this->show();
}

DoctorsTurn::~DoctorsTurn() {
    delete ui;
}

std::unique_ptr<IUiView> DoctorsTurn::CreateMethod() {
    return std::make_unique<DoctorsTurn>();
}

UiViews DoctorsTurn::GetFactoryName() {
    return DOCTORS_TURN;
}

void DoctorsTurn::hideUi() {
    this->hide();
}

void DoctorsTurn::on_nextNightButton_clicked() {
//    if (!this->accessGLM().isTurnPassed(DOCTOR)) {
    this->accessGH().loadUiGameView(DOCTORS_KILL_OR_HEAL_CHOICE);
    this->accessGH().changeUiView(DOCTORS_KILL_OR_HEAL_CHOICE);
//    } else {
//        this->accessGH().loadUiGameView(DOCTORS_RECAP);
//        this->accessGH().changeUiView(DOCTORS_RECAP);
//    }
}
