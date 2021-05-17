/*!

\file MutantsRecap.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include <QMessageBox>
#include "./Phases/Night/Mutant/ui_recap.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Mutant/MutantsRecap.hpp"

MutantsRecap::MutantsRecap(QWidget *parent)
        : QWidget(parent), ui(new Ui::MutantsRecap), RegisteredInFactory<MutantsRecap>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void MutantsRecap::showUi() {
    auto &glm = this->accessGLM();
    auto results = glm.computeAndLogMutantResult();
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    std::string labelText = "Tapez ";
    if (results[glm.getMutantsChoiceTarget()]) {
        if (glm.getMutantsChoice() == KILLING)
            labelText += "1 fois sur la tête de " + glm.getPlayerName(glm.getMutantsChoiceTarget()) + " et ";
        else
            labelText += "2 fois sur la tête de " + glm.getPlayerName(glm.getMutantsChoiceTarget()) + " et ";
    } else {
        labelText += "2 fois sur la tête et 1 fois sur l'épaule de " + glm.getPlayerName(glm.getMutantsChoiceTarget()) + " et ";
    }
    labelText += "3 fois sur celle de " + glm.getPlayerName(glm.getMutantsParalysisTarget());
    this->ui->mutantResult->setText(labelText.c_str());
    this->show();
}

MutantsRecap::~MutantsRecap() {
    delete ui;
}

std::unique_ptr<IUiView> MutantsRecap::CreateMethod() {
    return std::make_unique<MutantsRecap>();
}

UiViews MutantsRecap::GetFactoryName() {
    return MUTANTS_RECAP;
}

void MutantsRecap::hideUi() {
    this->hide();
}

void MutantsRecap::on_nextNightButton_clicked() {
    if (this->accessGLM().checkForMutantsWin()) {
        this->ui->nextNightButton->setDisabled(true);
        QMessageBox::information(this, "Fin de la partie", "Annoncez de votre plus belle manière la défaite de l'humanité.");
        this->accessGLM().resetGame();
        this->accessGH().clearUiGameViews();
    } else {
        this->accessGH().loadUiGameView(DOCTORS_TURN);
        this->accessGH().changeUiView(DOCTORS_TURN);
    }
}
