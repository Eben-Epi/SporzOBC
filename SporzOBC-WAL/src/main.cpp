#include "./ui_calculatorform.h"
#include <QApplication>
#include <QWidget>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget widget;
    Ui::CalculatorForm ui;
    ui.setupUi(&widget);

    widget.show();
    return app.exec();
}
