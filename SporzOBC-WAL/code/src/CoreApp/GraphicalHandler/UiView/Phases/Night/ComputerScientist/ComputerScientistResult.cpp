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
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void ComputerScientistResult::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    auto aliveMutantsNumber = this->accessGLM().getAlivePlayersAssociatedWithRole(MUTANT);
    std::string labelText;
    labelText += "Il y a " + std::to_string(aliveMutantsNumber.size()) + " mutant" + (aliveMutantsNumber.size() > 1 ? "s " : " ") + "à bord.";
    this->ui->aliveMutantsNumber->setText(labelText.c_str());
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

void ComputerScientistResult::on_nextNightButton_clicked() {
    this->accessGLM().setTurnPassed(COMPUTER_SCIENTIST);
    this->accessGH().loadUiGameView(GENETICIST_TURN);
    this->accessGH().changeUiView(GENETICIST_TURN);
}
