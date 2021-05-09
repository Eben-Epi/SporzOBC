/*!

\file Elimination.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Day/ui_elimination.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Day/Elimination.hpp"

Elimination::Elimination(QWidget *parent)
        : QWidget(parent), ui(new Ui::Elimination), RegisteredInFactory<Elimination>()
{
    ui->setupUi(this);
}

void Elimination::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

Elimination::~Elimination() {
    delete ui;
}

std::unique_ptr<IUiView> Elimination::CreateMethod() {
    return std::make_unique<Elimination>();
}

UiViews Elimination::GetFactoryName() {
    return ELIMINATION;
}

void Elimination::hideUi() {
    this->hide();
}

void Elimination::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(EVENING_BED_TIME);
    this->accessGH().changeUiView(EVENING_BED_TIME);
}
