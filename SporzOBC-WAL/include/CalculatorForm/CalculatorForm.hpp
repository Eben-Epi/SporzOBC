#ifndef SPORZOBC_WAL_CALCULATORFORM_HPP
#define SPORZOBC_WAL_CALCULATORFORM_HPP
#include <QWidget>
#include "./ui_calculatorform.h"
#include "./ui_homepage.h"

class CalculatorForm : public QWidget
{
    Q_OBJECT

public:
    explicit CalculatorForm(QWidget *parent = nullptr);

private slots:
    void on_inputSpinBox1_valueChanged(int value);
    void on_inputSpinBox2_valueChanged(int value);

private:
    Ui::CalculatorForm ui;
    Ui::Homepage ui2;
};

#endif //SPORZOBC_WAL_CALCULATORFORM_HPP
