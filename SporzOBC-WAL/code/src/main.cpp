#include <QApplication>
#include "CoreApp/CoreApp.hpp"
#include <iostream>
#include <CoreApp/IGraphicalHandler/IUiView/UiView/CalculatorForm/Calculator.hpp>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Calculator CalculatorPage;
    CoreApp appSporz;
//    auto CalculatorPage = UiViewFactory::Create("CALCULATOR");

//    std::cout << "fiu" << std::endl;
    CalculatorPage.showUi();
    return app.exec();
}
