#include <QApplication>
#include "CoreApp/CoreApp.hpp"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    CoreApp appSporz;
    auto CalculatorPage = UiViewFactory::Create(CALCULATOR);

    CalculatorPage->showUi();
    return app.exec();
}
