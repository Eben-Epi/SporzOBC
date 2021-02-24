#ifndef SPORZOBC_WAL_CALCULATOR_HPP
#define SPORZOBC_WAL_CALCULATOR_HPP
#include <QWidget>

namespace Ui {
    class CalculatorForm;
}

class Calculator : public QWidget
{
    Q_OBJECT

public:
    explicit Calculator(QWidget *parent = nullptr);
    virtual ~Calculator();

private slots:
    void on_inputSpinBox1_valueChanged(int value);
    void on_inputSpinBox2_valueChanged(int value);

private:
    Ui::CalculatorForm *ui;
};

#endif //SPORZOBC_WAL_CALCULATOR_HPP
