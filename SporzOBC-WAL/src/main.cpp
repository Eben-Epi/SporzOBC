#include <QApplication>
#include <CalculatorForm/Calculator.hpp>


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    Calculator ui;

    ui.show();
    return app.exec();
}
