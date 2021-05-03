/*!

\file PainterTurn.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Painter/ui_turn.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Painter/PainterTurn.hpp"

PainterTurn::PainterTurn(QWidget *parent)
        : QWidget(parent), ui(new Ui::PainterTurn), RegisteredInFactory<PainterTurn>()
{
    ui->setupUi(this);
}

void PainterTurn::showUi() {
    this->show();
}

PainterTurn::~PainterTurn() {
    delete ui;
}

std::unique_ptr<IUiView> PainterTurn::CreateMethod() {
    return std::make_unique<PainterTurn>();
}

UiViews PainterTurn::GetFactoryName() {
    return PAINTER_TURN;
}

void PainterTurn::hideUi() {
    this->hide();
}

void PainterTurn::on_nextButton_clicked() {
    if (!this->accessGLM().isTurnPassed(PAINTER)) {
        this->accessGH().loadUiGameView(PAINTER_TARGET);
        this->accessGH().changeUiView(PAINTER_TARGET);
    } else {
        this->accessGH().loadUiGameView(MORNING_WAKING_UP);
        this->accessGH().changeUiView(MORNING_WAKING_UP);
    }
}
