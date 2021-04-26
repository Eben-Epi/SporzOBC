/*!

\file NameList.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_PLAYERNAMELIST_HPP
#define SPORZOBC_WAL_PLAYERNAMELIST_HPP

#include <QListWidget>
#include "CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp"

class PlayerNameList : public QListWidget, public GameUiWidget {
Q_OBJECT

public:
    explicit PlayerNameList(QWidget *Parent = nullptr);
    ~PlayerNameList() override = default;

    void init();
};

#endif //SPORZOBC_WAL_PLAYERNAMELIST_HPP
