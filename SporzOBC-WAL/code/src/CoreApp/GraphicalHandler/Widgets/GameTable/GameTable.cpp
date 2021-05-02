/*!

\file GameTable.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include "CoreApp/IGraphicalHandler/Widgets/GameTable/GameTable.hpp"

#include <QMimeData>
#include <QDebug>
#include <CoreApp/IGraphicalHandler/Widgets/GameTable/GameInformationModel.hpp>

GameTable::GameTable(QWidget *parent)
        : QTableView(parent) {
    setModel(new GameInformationModel(parent));
}

void GameTable::updateAfterRand() {
    static_cast<GameInformationModel*>(this->model())->refreshAllTable();
}
