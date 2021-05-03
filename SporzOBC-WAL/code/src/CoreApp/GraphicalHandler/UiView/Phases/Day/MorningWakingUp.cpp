/*!

\file MorningWakingUp.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Day/ui_morning_waking_up.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Day/MorningWakingUp.hpp"

MorningWakingUp::MorningWakingUp(QWidget *parent)
        : QWidget(parent), ui(new Ui::MorningWakingUp), RegisteredInFactory<MorningWakingUp>()
{
    ui->setupUi(this);
}

void MorningWakingUp::showUi() {
    this->show();
}

MorningWakingUp::~MorningWakingUp() {
    delete ui;
}

std::unique_ptr<IUiView> MorningWakingUp::CreateMethod() {
    return std::make_unique<MorningWakingUp>();
}

UiViews MorningWakingUp::GetFactoryName() {
    return MORNING_WAKING_UP;
}

void MorningWakingUp::hideUi() {
    this->hide();
}

void MorningWakingUp::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(DISCUSS);
    this->accessGH().changeUiView(DISCUSS);
}
