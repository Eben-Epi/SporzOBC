/*!

\file GeneticistResult.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Geneticist/ui_result.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Geneticist/GeneticistResult.hpp"

GeneticistResult::GeneticistResult(QWidget *parent)
        : QWidget(parent), ui(new Ui::GeneticistResult), RegisteredInFactory<GeneticistResult>()
{
    ui->setupUi(this);
}

void GeneticistResult::showUi() {
    this->show();
}

GeneticistResult::~GeneticistResult() {
    delete ui;
}

std::unique_ptr<IUiView> GeneticistResult::CreateMethod() {
    return std::make_unique<GeneticistResult>();
}

UiViews GeneticistResult::GetFactoryName() {
    return GENETICIST_RESULT;
}

void GeneticistResult::hideUi() {
    this->hide();
}

void GeneticistResult::on_nextButton_clicked() {
    this->accessGLM().setTurnPassed(GENETICIST);
    this->accessGH().loadUiGameView(GENETICIST_TURN);
    this->accessGH().changeUiView(GENETICIST_TURN);
}
