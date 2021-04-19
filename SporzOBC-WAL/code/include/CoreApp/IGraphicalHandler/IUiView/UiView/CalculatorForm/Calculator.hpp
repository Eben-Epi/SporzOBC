#ifndef SPORZOBC_WAL_CALCULATOR_HPP
#define SPORZOBC_WAL_CALCULATOR_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class CalculatorForm;
}

class Calculator : public QWidget, public IUiView, public RegisteredInFactory<Calculator>
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = nullptr);
    virtual ~Calculator();

    virtual void showUi() override;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();


private slots:
    void on_inputSpinBox1_valueChanged(int value);
    void on_inputSpinBox2_valueChanged(int value);

private:
    Ui::CalculatorForm *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_CALCULATOR_HPP
