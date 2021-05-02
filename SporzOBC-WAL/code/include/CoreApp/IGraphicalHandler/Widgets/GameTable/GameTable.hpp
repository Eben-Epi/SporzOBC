/*!

\file GameTable.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_GAMETABLE_HPP
#define SPORZOBC_WAL_GAMETABLE_HPP

#include <QTableView>

class GameTable : public QTableView {
Q_OBJECT
public:
    explicit GameTable(QWidget *parent = nullptr);
    void updateAfterRand();
};
#endif //SPORZOBC_WAL_GAMETABLE_HPP
