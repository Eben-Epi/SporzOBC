#include <QApplication>
#include <iostream>
#include "CoreApp/CoreApp.hpp"

int main(int argc, char **argv)
{
    try {
//        QApplication::setAttribute(Qt::AA_Use96Dpi);
//        QApplication::setAttribute(Qt::AA_DisableHighDpiScaling);
        CoreApp appSporz(argc, argv);
        return appSporz.graphicalHandlerReturnCode();
    } catch (SporzException& e) {
        std::cout << e.what();
        return -1;
    }
}
