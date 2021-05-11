/*!

\file PainterTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Painter/ui_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Painter/PainterTarget.hpp"

PainterTarget::PainterTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::PainterTarget), RegisteredInFactory<PainterTarget>()
{
    ui->setupUi(this);
}

void PainterTarget::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

PainterTarget::~PainterTarget() {
    delete ui;
}

std::unique_ptr<IUiView> PainterTarget::CreateMethod() {
    return std::make_unique<PainterTarget>();
}

UiViews PainterTarget::GetFactoryName() {
    return PAINTER_TARGET;
}

void PainterTarget::hideUi() {
    this->hide();
}

void PainterTarget::on_nextNightButton_clicked() {
    this->accessGH().loadUiGameView(PAINTER_RESULT);
    this->accessGH().changeUiView(PAINTER_RESULT);
}
