/*!

\file ElectChief.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include "./ui_elect_chief.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/ElectChief.hpp"

ElectChief::ElectChief(QWidget *parent)
        : QWidget(parent), ui(new Ui::ElectChief), RegisteredInFactory<ElectChief>()
{
    ui->setupUi(this);
}

void ElectChief::showUi() {
    this->fillComboBox();
    this->show();
}

ElectChief::~ElectChief() {
    delete ui;
}

std::unique_ptr<IUiView> ElectChief::CreateMethod() {
    return std::make_unique<ElectChief>();
}

UiViews ElectChief::GetFactoryName() {
    return ELECT_CHIEF;
}

void ElectChief::hideUi() {
    this->hide();
}

void ElectChief::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(EVENING_BED_TIME);
    this->accessGH().changeUiView(EVENING_BED_TIME);
}

void ElectChief::fillComboBox() {
    auto &glm = this->accessGLM();
    int playerCount = glm.getPlayerCount();
    QStringList names;

    for (int ID = 1; ID <= playerCount; ID++)
        names.push_back(QString::fromUtf8(glm.getPlayerName(ID).c_str()));
    glm.assignChief(1);
    this->ui->selectChief->addItems(names);
}

void ElectChief::on_selectChief_currentIndexChanged(int index) {
    this->accessGLM().assignChief(index + 1);
}
