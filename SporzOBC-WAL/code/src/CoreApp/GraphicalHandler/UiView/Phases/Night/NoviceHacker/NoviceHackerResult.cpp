/*!

\file NoviceHackerResult.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/NoviceHacker/ui_result.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/NoviceHacker/NoviceHackerResult.hpp"

NoviceHackerResult::NoviceHackerResult(QWidget *parent)
        : QWidget(parent), ui(new Ui::NoviceHackerResult), RegisteredInFactory<NoviceHackerResult>()
{
    ui->setupUi(this);
}

void NoviceHackerResult::showUi() {
    this->show();
}

NoviceHackerResult::~NoviceHackerResult() {
    delete ui;
}

std::unique_ptr<IUiView> NoviceHackerResult::CreateMethod() {
    return std::make_unique<NoviceHackerResult>();
}

UiViews NoviceHackerResult::GetFactoryName() {
    return NOVICE_HACKER_RESULT;
}

void NoviceHackerResult::hideUi() {
    this->hide();
}

void NoviceHackerResult::on_nextButton_clicked() {
    this->accessGLM().setTurnPassed(NOVICE_HACKER);
    this->accessGH().loadUiGameView(NOVICE_HACKER_TURN);
    this->accessGH().changeUiView(NOVICE_HACKER_TURN);
}
