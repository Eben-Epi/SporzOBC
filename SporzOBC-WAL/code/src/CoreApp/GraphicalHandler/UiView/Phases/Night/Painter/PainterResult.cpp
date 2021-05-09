/*!

\file PainterResult.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Painter/ui_result.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Painter/PainterResult.hpp"

PainterResult::PainterResult(QWidget *parent)
        : QWidget(parent), ui(new Ui::PainterResult), RegisteredInFactory<PainterResult>()
{
    ui->setupUi(this);
}

void PainterResult::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

PainterResult::~PainterResult() {
    delete ui;
}

std::unique_ptr<IUiView> PainterResult::CreateMethod() {
    return std::make_unique<PainterResult>();
}

UiViews PainterResult::GetFactoryName() {
    return PAINTER_RESULT;
}

void PainterResult::hideUi() {
    this->hide();
}

void PainterResult::on_nextButton_clicked() {
    this->accessGLM().setTurnPassed(PAINTER);
    this->accessGH().loadUiGameView(MORNING_WAKING_UP);
    this->accessGH().changeUiView(MORNING_WAKING_UP);
}
