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
}

void DoctorsTurn::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
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
