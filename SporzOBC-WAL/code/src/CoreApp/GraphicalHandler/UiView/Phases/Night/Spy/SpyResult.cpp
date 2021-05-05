/*!

\file SpyResult.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Spy/ui_result.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Spy/SpyResult.hpp"

SpyResult::SpyResult(QWidget *parent)
        : QWidget(parent), ui(new Ui::SpyResult), RegisteredInFactory<SpyResult>()
{
    ui->setupUi(this);
}

void SpyResult::showUi() {
    this->show();
}

SpyResult::~SpyResult() {
    delete ui;
}

std::unique_ptr<IUiView> SpyResult::CreateMethod() {
    return std::make_unique<SpyResult>();
}

UiViews SpyResult::GetFactoryName() {
    return SPY_RESULT;
}

void SpyResult::hideUi() {
    this->hide();
}

void SpyResult::on_nextButton_clicked() {
    this->accessGLM().setTurnPassed(SPY);
    if (this->accessGLM().getPlayerCount() > 9) {
        this->accessGH().loadUiGameView(PAINTER_TURN);
        this->accessGH().changeUiView(PAINTER_TURN);
    } else {
        this->accessGH().loadUiGameView(MORNING_WAKING_UP);
        this->accessGH().changeUiView(MORNING_WAKING_UP);
    }
}
