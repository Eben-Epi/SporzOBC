#ifndef SPORZOBC_WAL_CALCULATOR_HPP
#define SPORZOBC_WAL_CALCULATOR_HPP

#include <QWidget>
#include <CoreApp/IGraphicalHandler/IUiView/IUiView.hpp>

namespace Ui {
    class CalculatorForm;
}

class Calculator : public QWidget, public IUiView
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    virtual ~Calculator();

    virtual void showUi() override;


private slots:
    void on_inputSpinBox1_valueChanged(int value);
    void on_inputSpinBox2_valueChanged(int value);

private:
    Ui::CalculatorForm *ui;
};

#endif //SPORZOBC_WAL_CALCULATOR_HPP
