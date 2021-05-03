/*!

\file SpyTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./Phases/Night/Spy/ui_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Spy/SpyTarget.hpp"

SpyTarget::SpyTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::SpyTarget), RegisteredInFactory<SpyTarget>()
{
    ui->setupUi(this);
}

void SpyTarget::showUi() {
    this->show();
}

SpyTarget::~SpyTarget() {
    delete ui;
}

std::unique_ptr<IUiView> SpyTarget::CreateMethod() {
    return std::make_unique<SpyTarget>();
}

UiViews SpyTarget::GetFactoryName() {
    return SPY_TARGET;
}

void SpyTarget::hideUi() {
    this->hide();
}

void SpyTarget::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(SPY_RESULT);
    this->accessGH().changeUiView(SPY_RESULT);
}
