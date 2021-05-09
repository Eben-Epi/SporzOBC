/*!

\file NoviceHackerTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/NoviceHacker/ui_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/NoviceHacker/NoviceHackerTarget.hpp"

NoviceHackerTarget::NoviceHackerTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::NoviceHackerTarget), RegisteredInFactory<NoviceHackerTarget>()
{
    ui->setupUi(this);
}

void NoviceHackerTarget::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

NoviceHackerTarget::~NoviceHackerTarget() {
    delete ui;
}

std::unique_ptr<IUiView> NoviceHackerTarget::CreateMethod() {
    return std::make_unique<NoviceHackerTarget>();
}

UiViews NoviceHackerTarget::GetFactoryName() {
    return NOVICE_HACKER_TARGET;
}

void NoviceHackerTarget::hideUi() {
    this->hide();
}

void NoviceHackerTarget::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(NOVICE_HACKER_RESULT);
    this->accessGH().changeUiView(NOVICE_HACKER_RESULT);
}
