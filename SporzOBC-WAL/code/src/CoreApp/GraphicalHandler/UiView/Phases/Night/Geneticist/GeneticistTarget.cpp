/*!

\file GeneticistTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Geneticist/ui_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Geneticist/GeneticistTarget.hpp"

GeneticistTarget::GeneticistTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::GeneticistTarget), RegisteredInFactory<GeneticistTarget>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void GeneticistTarget::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

GeneticistTarget::~GeneticistTarget() {
    delete ui;
}

std::unique_ptr<IUiView> GeneticistTarget::CreateMethod() {
    return std::make_unique<GeneticistTarget>();
}

UiViews GeneticistTarget::GetFactoryName() {
    return GENETICIST_TARGET;
}

void GeneticistTarget::hideUi() {
    this->hide();
}

void GeneticistTarget::on_nextNightButton_clicked() {
    this->accessGH().loadUiGameView(GENETICIST_RESULT);
    this->accessGH().changeUiView(GENETICIST_RESULT);
}
