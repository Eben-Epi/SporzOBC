#include <QApplication>
#include <iostream>
#include "CoreApp/CoreApp.hpp"

int main(int argc, char **argv)
{
    try {
        QApplication app(argc, argv);
        CoreApp appSporz;

        appSporz.initGraphicalHandler();
        appSporz.play();
        return app.exec();
    } catch (SporzException& e) {
        std::cout << e.what();
    }
}
