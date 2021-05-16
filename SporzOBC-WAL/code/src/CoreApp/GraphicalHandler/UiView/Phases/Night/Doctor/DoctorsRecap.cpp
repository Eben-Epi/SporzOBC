/*!

\file DoctorsRecap.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Doctor/ui_recap.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Doctor/DoctorsRecap.hpp"

DoctorsRecap::DoctorsRecap(QWidget *parent)
        : QWidget(parent), ui(new Ui::DoctorsRecap), RegisteredInFactory<DoctorsRecap>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void DoctorsRecap::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

DoctorsRecap::~DoctorsRecap() {
    delete ui;
}

std::unique_ptr<IUiView> DoctorsRecap::CreateMethod() {
    return std::make_unique<DoctorsRecap>();
}

UiViews DoctorsRecap::GetFactoryName() {
    return DOCTORS_RECAP;
}

void DoctorsRecap::hideUi() {
    this->hide();
}

void DoctorsRecap::on_nextNightButton_clicked() {
    this->accessGH().loadUiGameView(COMPUTER_SCIENTIST_TURN);
    this->accessGH().changeUiView(COMPUTER_SCIENTIST_TURN);
}
