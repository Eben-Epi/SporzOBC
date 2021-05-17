/*!

\file ElectChief.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./ui_elect_chief.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/ElectChief.hpp"

ElectChief::ElectChief(QWidget *parent)
        : QWidget(parent), ui(new Ui::ElectChief), RegisteredInFactory<ElectChief>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void ElectChief::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
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
    this->accessGLM().logCreateGame();
    this->accessGH().loadUiGameView(EVENING_BED_TIME);
    this->accessGH().changeUiView(EVENING_BED_TIME);
}

void ElectChief::fillComboBox() {
    auto &glm = this->accessGLM();
    auto players = glm.getAlivePlayers();
    QStringList names;

    for (auto player : players)
        names.push_back(QString::fromUtf8(player->getUserName().c_str()));
    glm.assignChief(players[0]->getID());
    this->ui->selectChief->addItems(names);
}

void ElectChief::on_selectChief_currentIndexChanged(int index) {
    this->accessGLM().assignChief(this->accessGLM().getAlivePlayerIDByName(std::string(this->ui->selectChief->itemText(index).toUtf8().data())));
}
