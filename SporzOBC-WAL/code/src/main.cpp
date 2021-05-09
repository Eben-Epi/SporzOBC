#include <QApplication>
#include <iostream>
#include "CoreApp/CoreApp.hpp"

int main(int argc, char **argv)
{
    try {
        CoreApp appSporz(argc, argv);
        return appSporz.graphicalHandlerReturnCode();
    } catch (SporzException& e) {
        std::cout << e.what();
        return -1;
    }
}
