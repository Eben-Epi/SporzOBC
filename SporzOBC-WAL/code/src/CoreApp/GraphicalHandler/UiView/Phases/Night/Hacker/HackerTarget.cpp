/*!

\file HackerTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Hacker/ui_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Hacker/HackerTarget.hpp"

HackerTarget::HackerTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::HackerTarget), RegisteredInFactory<HackerTarget>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void HackerTarget::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

HackerTarget::~HackerTarget() {
    delete ui;
}

std::unique_ptr<IUiView> HackerTarget::CreateMethod() {
    return std::make_unique<HackerTarget>();
}

UiViews HackerTarget::GetFactoryName() {
    return HACKER_TARGET;
}

void HackerTarget::hideUi() {
    this->hide();
}

void HackerTarget::on_nextNightButton_clicked() {
    this->accessGH().loadUiGameView(HACKER_RESULT);
    this->accessGH().changeUiView(HACKER_RESULT);
}
