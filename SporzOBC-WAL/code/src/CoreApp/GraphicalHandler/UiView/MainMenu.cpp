/*!

\file MainMenu.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include "./ui_main_menu.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/MainMenu.hpp"

MainMenu::MainMenu(QWidget *parent)
        : QWidget(parent), ui(new Ui::MainMenu), RegisteredInFactory<MainMenu>()
{
    ui->setupUi(this);
}

void MainMenu::showUi() {
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
    this->accessGH().loadUiGameView(CALCULATOR);
    this->accessGH().changeUiView(CALCULATOR);
}

void MainMenu::on_quitButton_clicked() {
    this->close();
}
