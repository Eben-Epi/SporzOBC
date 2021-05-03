/*!

\file HackerResult.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Hacker/ui_result.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Hacker/HackerResult.hpp"

HackerResult::HackerResult(QWidget *parent)
        : QWidget(parent), ui(new Ui::HackerResult), RegisteredInFactory<HackerResult>()
{
    ui->setupUi(this);
}

void HackerResult::showUi() {
    this->show();
}

HackerResult::~HackerResult() {
    delete ui;
}

std::unique_ptr<IUiView> HackerResult::CreateMethod() {
    return std::make_unique<HackerResult>();
}

UiViews HackerResult::GetFactoryName() {
    return HACKER_RESULT;
}

void HackerResult::hideUi() {
    this->hide();
}

void HackerResult::on_nextButton_clicked() {
    this->accessGLM().setTurnPassed(HACKER);
    this->accessGH().loadUiGameView(HACKER_TURN);
    this->accessGH().changeUiView(HACKER_TURN);
}
