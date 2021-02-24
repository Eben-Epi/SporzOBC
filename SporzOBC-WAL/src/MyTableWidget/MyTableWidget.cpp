#include "MyTableWidget/MyTableWidget.hpp"

MyTableWidget::MyTableWidget(QWidget *parent) : QTableView(parent) {
 setModel(new MyModel);
}
