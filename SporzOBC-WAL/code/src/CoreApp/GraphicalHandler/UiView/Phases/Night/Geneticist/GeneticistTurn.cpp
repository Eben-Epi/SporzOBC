/*!

\file GeneticistTurn.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Geneticist/ui_turn.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Geneticist/GeneticistTurn.hpp"

GeneticistTurn::GeneticistTurn(QWidget *parent)
        : QWidget(parent), ui(new Ui::GeneticistTurn), RegisteredInFactory<GeneticistTurn>()
{
    ui->setupUi(this);
}

void GeneticistTurn::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

GeneticistTurn::~GeneticistTurn() {
    delete ui;
}

std::unique_ptr<IUiView> GeneticistTurn::CreateMethod() {
    return std::make_unique<GeneticistTurn>();
}

UiViews GeneticistTurn::GetFactoryName() {
    return GENETICIST_TURN;
}

void GeneticistTurn::hideUi() {
    this->hide();
}

void GeneticistTurn::on_nextNightButton_clicked() {
//    if (!this->accessGLM().isTurnPassed(GENETICIST)) {
        this->accessGH().loadUiGameView(GENETICIST_TARGET);
        this->accessGH().changeUiView(GENETICIST_TARGET);
//    } else {
//        this->accessGH().loadUiGameView(PSYCHOLOGIST_TURN);
//        this->accessGH().changeUiView(PSYCHOLOGIST_TURN);
//    }
}
