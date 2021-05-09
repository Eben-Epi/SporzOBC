/*!

\file PsychologistTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Psychologist/ui_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Psychologist/PsychologistTarget.hpp"

PsychologistTarget::PsychologistTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::PsychologistTarget), RegisteredInFactory<PsychologistTarget>()
{
    ui->setupUi(this);
}

void PsychologistTarget::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

PsychologistTarget::~PsychologistTarget() {
    delete ui;
}

std::unique_ptr<IUiView> PsychologistTarget::CreateMethod() {
    return std::make_unique<PsychologistTarget>();
}

UiViews PsychologistTarget::GetFactoryName() {
    return PSYCHOLOGIST_TARGET;
}

void PsychologistTarget::hideUi() {
    this->hide();
}

void PsychologistTarget::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(PSYCHOLOGIST_RESULT);
    this->accessGH().changeUiView(PSYCHOLOGIST_RESULT);
}
