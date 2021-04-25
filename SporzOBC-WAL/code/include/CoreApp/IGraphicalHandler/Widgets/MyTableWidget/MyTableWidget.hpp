#ifndef SPORZOBC_WAL_MYTABLEWIDGET_HPP
#define SPORZOBC_WAL_MYTABLEWIDGET_HPP

#include <QTableView>
#include <CoreApp/IGraphicalHandler/Widgets/MyModel/MyModel.hpp>

class MyTableWidget : public QTableView {
    Q_OBJECT
public:
    explicit MyTableWidget(QWidget *parent = nullptr);
};

#endif //SPORZOBC_WAL_MYTABLEWIDGET_HPP
