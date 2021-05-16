/*!

\file EveningBedTime.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/ui_evening_bed_time.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Day/EveningBedTime.hpp"

EveningBedTime::EveningBedTime(QWidget *parent)
        : QWidget(parent), ui(new Ui::EveningBedTime), RegisteredInFactory<EveningBedTime>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void EveningBedTime::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

EveningBedTime::~EveningBedTime() {
    delete ui;
}

std::unique_ptr<IUiView> EveningBedTime::CreateMethod() {
    return std::make_unique<EveningBedTime>();
}

UiViews EveningBedTime::GetFactoryName() {
    return EVENING_BED_TIME;
}

void EveningBedTime::hideUi() {
    this->hide();
}

void EveningBedTime::on_nextButton_clicked() {
    this->accessGLM().resetTurns();
    this->accessGH().loadUiGameView(MUTANTS_TURN);
    this->accessGH().changeUiView(MUTANTS_TURN);
}
