/*!

\file ComputerScientistResult.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/ComputerScientist/ui_result.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/ComputerScientist/ComputerScientistResult.hpp"

ComputerScientistResult::ComputerScientistResult(QWidget *parent)
        : QWidget(parent), ui(new Ui::ComputerScientistResult), RegisteredInFactory<ComputerScientistResult>()
{
    ui->setupUi(this);
}

void ComputerScientistResult::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

ComputerScientistResult::~ComputerScientistResult() {
    delete ui;
}

std::unique_ptr<IUiView> ComputerScientistResult::CreateMethod() {
    return std::make_unique<ComputerScientistResult>();
}

UiViews ComputerScientistResult::GetFactoryName() {
    return COMPUTER_SCIENTIST_RESULT;
}

void ComputerScientistResult::hideUi() {
    this->hide();
}

void ComputerScientistResult::on_nextButton_clicked() {
    this->accessGLM().setTurnPassed(COMPUTER_SCIENTIST);
    this->accessGH().loadUiGameView(GENETICIST_TURN);
    this->accessGH().changeUiView(GENETICIST_TURN);
}
