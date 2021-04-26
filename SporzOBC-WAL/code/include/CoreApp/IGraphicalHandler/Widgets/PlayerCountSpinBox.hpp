/*!

\file PlayerCountSpinBox.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PLAYERCOUNTSPINBOX_HPP
#define SPORZOBC_WAL_PLAYERCOUNTSPINBOX_HPP

#include <QString>
#include <QSpinBox>
#include "CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp"

class PlayerCountSpinBox : public QSpinBox, public GameUiWidget {
Q_OBJECT

public:
    explicit PlayerCountSpinBox(QWidget *Parent = nullptr);
    ~PlayerCountSpinBox() override = default;

    void init();
};

#endif //SPORZOBC_WAL_PLAYERCOUNTSPINBOX_HPP
