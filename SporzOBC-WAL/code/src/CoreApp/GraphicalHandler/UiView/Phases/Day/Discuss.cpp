/*!

\file Discuss.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Day/ui_discuss.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Day/Discuss.hpp"

Discuss::Discuss(QWidget *parent)
        : QWidget(parent), ui(new Ui::Discuss), RegisteredInFactory<Discuss>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void Discuss::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

Discuss::~Discuss() {
    delete ui;
}

std::unique_ptr<IUiView> Discuss::CreateMethod() {
    return std::make_unique<Discuss>();
}

UiViews Discuss::GetFactoryName() {
    return DISCUSS;
}

void Discuss::hideUi() {
    this->hide();
}

void Discuss::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(VOTING_PHASE_TARGET);
    this->accessGH().changeUiView(VOTING_PHASE_TARGET);
}
