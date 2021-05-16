/*!

\file PlayerSelect.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <QMessageBox>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/PlayerSelect.hpp"
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./ui_player_select.h"

PlayerSelect::PlayerSelect(QWidget *parent)
        : QWidget(parent), ui(new Ui::PlayerSelect), RegisteredInFactory<PlayerSelect>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void PlayerSelect::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->ui->playerCountSpinBox->setValue(this->accessGLM().getPlayerCount());
    this->ui->playerCountSpinBox->setRange(MIN_PLAYER_SIZE, MAX_PLAYER_SIZE);
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

void PlayerSelect::on_playerNameList_itemChanged(QListWidgetItem *item) {
    auto &glm = this->accessGLM();
    size_t ID = this->ui->playerNameList->row(item) + 1;
    std::string newName = item->text().toUtf8().constData();

    try {
        glm.setPlayerName(ID, newName);
    } catch (GameLogicManagerException &e) {
        if (e.type == PLAYER_NAME_TOO_LONG) {
            item->setText(QString::fromUtf8(glm.getPlayerName(ID).c_str()));
            QMessageBox::information(this, "Changement du nom du joueur", "Le nom d'un joueur ne dépasse pas 15 caractères !");
        }
    }
}

void PlayerSelect::on_playerCountSpinBox_valueChanged(int desiredSize) {
    auto &glm = this->accessGLM();
    QListWidgetItem *item_ptr;
    int listSize = this->ui->playerNameList->count();
    int counter = listSize < desiredSize ? 1 : -1;

    glm.setPlayerCount(desiredSize);

    if (counter == listSize)
        return;

    while (desiredSize != listSize) {
        if (listSize < desiredSize) {
            item_ptr = new QListWidgetItem(QString::fromUtf8(glm.getPlayerName(listSize + 1).c_str()));
            item_ptr->setFlags(item_ptr->flags() | Qt::ItemIsEditable);
            item_ptr->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignHCenter);
            this->ui->playerNameList->addItem(item_ptr);
        } else {
            item_ptr = this->ui->playerNameList->takeItem(listSize - 1);
            delete(item_ptr);
        }
        listSize += counter;
    }
}

void PlayerSelect::on_nextButton_clicked() {
    this->accessGH().loadUiGameView(GAME_INFORMATION);
    this->accessGH().changeUiView(GAME_INFORMATION);
}
