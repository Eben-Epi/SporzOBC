/*!

\file MutantsKillOrMutateTarget.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./Phases/Night/Mutant/ui_kill_or_mutate_target.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Mutant/MutantsKillOrMutateTarget.hpp"

MutantsKillOrMutateTarget::MutantsKillOrMutateTarget(QWidget *parent)
        : QWidget(parent), ui(new Ui::MutantsKillOrMutateTarget), RegisteredInFactory<MutantsKillOrMutateTarget>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void MutantsKillOrMutateTarget::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->fillComboBox();
    this->show();
}

MutantsKillOrMutateTarget::~MutantsKillOrMutateTarget() {
    delete ui;
}

std::unique_ptr<IUiView> MutantsKillOrMutateTarget::CreateMethod() {
    return std::make_unique<MutantsKillOrMutateTarget>();
}

UiViews MutantsKillOrMutateTarget::GetFactoryName() {
    return MUTANTS_KILL_OR_MUTATE_TARGET;
}

void MutantsKillOrMutateTarget::hideUi() {
    this->hide();
}

void MutantsKillOrMutateTarget::on_nextNightButton_clicked() {
    this->accessGLM().logMutantChoiceTarget();
    this->accessGH().loadUiGameView(MUTANT_PARALYSIS_TARGET);
    this->accessGH().changeUiView(MUTANT_PARALYSIS_TARGET);
}

void MutantsKillOrMutateTarget::fillComboBox() {
    auto &glm = this->accessGLM();
    auto possibleTargets = glm.getAlivePlayersTargetedByRole(MUTANT);
    QStringList names;

    for (auto &target : possibleTargets)
        names.push_back((target->getUserName()).c_str());
    this->ui->selectTarget->addItems(names);
}

void MutantsKillOrMutateTarget::on_selectTarget_currentTextChanged(const QString &text) {
    std::string username = text.toUtf8().constData();
    this->accessGLM().setMutantsChoiceTarget(this->accessGLM().getAlivePlayerIDByName(username));
}
