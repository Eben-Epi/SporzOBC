#include <QApplication>
#include <CalculatorForm/CalculatorForm.hpp>


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    CalculatorForm ui;

    ui.show();
    return app.exec();
}
