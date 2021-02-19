#include "../include/homepage.h"

#include <QApplication>
#include <QTableView>
#include <MyModel/MyModel.hpp>

int main(int argc, char **argv)
{
    QApplication a(argc, argv);
    QTableView tableView;
    MyModel model;
    tableView.setModel(&model);
    tableView.show();
//    Homepage w;
//    w.show();
    return a.exec();
}
