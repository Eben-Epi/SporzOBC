/*!

\file PlayerCountSpinBox.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include "CoreApp/IGraphicalHandler/Widgets/PlayerCountSpinBox.hpp"

PlayerCountSpinBox::PlayerCountSpinBox(QWidget *Parent) : GameUiModel() {

}

void PlayerCountSpinBox::init() {
    this->setValue(this->accessGLM().getPlayerCount());
    this->setRange(MIN_PLAYER_SIZE, MAX_PLAYER_SIZE);
    connect(this, QOverload<int>::of(&QSpinBox::valueChanged),
            [=](int i){ this->accessGLM().setPlayerCount(i); });
}
