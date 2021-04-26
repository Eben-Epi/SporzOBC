/*!

\file PlayerNameList.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include "CoreApp/IGraphicalHandler/Widgets/PlayerNameList.hpp"

PlayerNameList::PlayerNameList(QWidget *Parent) : GameUiWidget(), QListWidget(Parent) {

}

void PlayerNameList::init() {
        QListWidgetItem *item_ptr;
        auto &glm = this->accessGLM();

    for (auto playerName : this->accessGLM().getPlayerNames()) {
        item_ptr = new QListWidgetItem(QString::fromUtf8(playerName.c_str()));
        item_ptr->setFlags(item_ptr->flags() | Qt::ItemIsEditable);
        this->addItem(item_ptr);
    }
}
