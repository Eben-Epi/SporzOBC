//#include <QApplication>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"
#include "CoreApp/CoreApp.hpp"
#include <iostream>

std::map<std::string, UiViewFactory::TCreateMethod> UiViewFactory::sUiViews;

int main(int argc, char **argv)
{
//    QApplication app(argc, argv);
//    Calculator CalculatorPage;
//    CoreApp appSporz;
    auto CalculatorPage = UiViewFactory::Create("CALCULATOR");

    std::cout << "fiu" << std::endl;
    CalculatorPage->showUi();
//    return app.exec();
}
