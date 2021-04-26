/*!

\file PlayerSelect.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include "CoreApp/IGraphicalHandler/IUiView/UiView/PlayerSelect.hpp"
#include "./ui_player_select.h"

PlayerSelect::PlayerSelect(QWidget *parent)
        : QWidget(parent), ui(new Ui::PlayerSelect), RegisteredInFactory<PlayerSelect>()
{
    ui->setupUi(this);
}

void PlayerSelect::showUi() {
    static_cast<GameUiModel*>(ui->playerCountSpinBox)->setGLM(this->accessGLM());
    ui->playerCountSpinBox->init();
    this->show();
}

PlayerSelect::~PlayerSelect() {
    delete ui;
}

std::unique_ptr<IUiView> PlayerSelect::CreateMethod() {
    return std::make_unique<PlayerSelect>();
}

UiViews PlayerSelect::GetFactoryName() {
    return PLAYER_SELECT;
}

void PlayerSelect::hideUi() {
    this->hide();
}

//void PlayerSelect::on_playButton_clicked() {
//    this->accessGH().loadUiGameView(CALCULATOR);
//    this->accessGH().changeUiView(CALCULATOR);
//}
//
//void PlayerSelect::on_quitButton_clicked() {
//    this->close();
//}