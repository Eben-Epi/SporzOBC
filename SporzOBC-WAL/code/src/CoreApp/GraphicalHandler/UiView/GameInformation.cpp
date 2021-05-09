/*!

\file GameInformation.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/


#include <CoreApp/IGraphicalHandler/Widgets/GameTable/GameTable.hpp>
#include <CoreApp/IGraphicalHandler/Widgets/GameTable/GameInformationModel.hpp>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/GameInformation.hpp"
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./ui_game_information.h"


GameInformation::GameInformation(QWidget *parent)
        : QWidget(parent), ui(new Ui::GameInformation), RegisteredInFactory<GameInformation>()
{
    ui->setupUi(this);
}

void GameInformation::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    auto gameTable = static_cast<GameInformationModel*>(this->ui->gameTable->model());
    gameTable->setGLM(this->accessGLM());

    this->accessGLM().randomizeRoles();
    this->accessGLM().randomizeGenomes();
    gameTable->init();
    this->ui->gameTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    this->show();
}

GameInformation::~GameInformation() {
    delete ui;
}

std::unique_ptr<IUiView> GameInformation::CreateMethod() {
    return std::make_unique<GameInformation>();
}

UiViews GameInformation::GetFactoryName() {
    return GAME_INFORMATION;
}

void GameInformation::hideUi() {
    this->hide();
}

void GameInformation::on_randGenomes_clicked() {
    this->accessGLM().randomizeGenomes();
    this->ui->gameTable->updateAfterRand();
}

void GameInformation::on_randRoles_clicked() {
    this->accessGLM().randomizeRoles();
    this->ui->gameTable->updateAfterRand();
}

void GameInformation::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(ELECT_CHIEF);
    this->accessGH().changeUiView(ELECT_CHIEF);
}