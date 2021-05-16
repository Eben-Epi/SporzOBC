/*!

\file MainMenu.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include "./ui_main_menu.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/MainMenu.hpp"

MainMenu::MainMenu(QWidget *parent)
        : QWidget(parent), ui(new Ui::MainMenu), RegisteredInFactory<MainMenu>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void MainMenu::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    this->show();
}

MainMenu::~MainMenu() {
    delete ui;
}

std::unique_ptr<IUiView> MainMenu::CreateMethod() {
    return std::make_unique<MainMenu>();
}

UiViews MainMenu::GetFactoryName() {
    return MAIN_MENU;
}

void MainMenu::hideUi() {
    this->hide();
}

void MainMenu::on_playButton_clicked() {
    this->accessGH().loadUiGameView(PLAYER_SELECT);
    this->accessGH().changeUiView(PLAYER_SELECT);
}

void MainMenu::on_quitButton_clicked() {
    this->close();
}
