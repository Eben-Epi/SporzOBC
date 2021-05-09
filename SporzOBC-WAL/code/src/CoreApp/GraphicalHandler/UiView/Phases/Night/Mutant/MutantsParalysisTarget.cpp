/*!

\file MutantsParalysisTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Mutant/ui_paralysis_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Mutant/MutantsParalysisTarget.hpp"

MutantsParalysisTarget::MutantsParalysisTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::MutantsParalysisTarget), RegisteredInFactory<MutantsParalysisTarget>()
{
    ui->setupUi(this);
}

void MutantsParalysisTarget::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->fillComboBox();
    this->show();
}

MutantsParalysisTarget::~MutantsParalysisTarget() {
    delete ui;
}

std::unique_ptr<IUiView> MutantsParalysisTarget::CreateMethod() {
    return std::make_unique<MutantsParalysisTarget>();
}

UiViews MutantsParalysisTarget::GetFactoryName() {
    return MUTANT_PARALYSIS_TARGET;
}

void MutantsParalysisTarget::hideUi() {
    this->hide();
}

void MutantsParalysisTarget::on_nextButton_clicked() {
    this->accessGLM().setTurnPassed(MUTANT);
    this->accessGH().loadUiGameView(MUTANTS_RECAP);
    this->accessGH().changeUiView(MUTANTS_RECAP);
}


void MutantsParalysisTarget::fillComboBox() {
    auto &glm = this->accessGLM();
    auto possibleTargets = glm.getAlivePlayersTargetedByRole(MUTANT);
    size_t lastIDToExclude = glm.getMutantsChoiceTarget();
    QStringList names;

    for (auto &target : possibleTargets) {
        if (target->getID() != lastIDToExclude)
            names.push_back((target->getUserName()).c_str());
    }
    this->ui->selectTarget->addItems(names);
}

void MutantsParalysisTarget::on_selectTarget_currentTextChanged(const QString &text) {
    std::string username = text.toUtf8().constData();
    this->accessGLM().setMutantsParalysisTarget((this->accessGLM().getAlivePlayerIDByName(username)));
}