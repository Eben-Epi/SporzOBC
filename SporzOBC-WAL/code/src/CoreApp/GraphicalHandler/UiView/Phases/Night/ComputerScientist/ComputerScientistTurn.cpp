/*!

\file ComputerScientistTurn.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/ComputerScientist/ui_turn.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/ComputerScientist/ComputerScientistTurn.hpp"

ComputerScientistTurn::ComputerScientistTurn(QWidget *parent)
        : QWidget(parent), ui(new Ui::ComputerScientistTurn), RegisteredInFactory<ComputerScientistTurn>()
{
    ui->setupUi(this);
}

void ComputerScientistTurn::showUi() {
    this->show();
}

ComputerScientistTurn::~ComputerScientistTurn() {
    delete ui;
}

std::unique_ptr<IUiView> ComputerScientistTurn::CreateMethod() {
    return std::make_unique<ComputerScientistTurn>();
}

UiViews ComputerScientistTurn::GetFactoryName() {
    return COMPUTER_SCIENTIST_TURN;
}

void ComputerScientistTurn::hideUi() {
    this->hide();
}

void ComputerScientistTurn::on_nextButton_clicked() {
//    if (!this->accessGLM().isTurnPassed(COMPUTER_SCIENTIST)) {
    this->accessGH().loadUiGameView(COMPUTER_SCIENTIST_RESULT);
    this->accessGH().changeUiView(COMPUTER_SCIENTIST_RESULT);
}
