#include "./ui_calculatorform.h"
#include <CalculatorForm/Calculator.hpp>


Calculator::Calculator(QWidget *parent)
        : QWidget(parent), ui(new Ui::CalculatorForm)
{
    ui->setupUi(this);
    ui2.setupUi(this);
}

void Calculator::on_inputSpinBox1_valueChanged(int value) {
    ui->outputWidget->setText(QString::number(value + ui->inputSpinBox2->value()));

}

void Calculator::on_inputSpinBox2_valueChanged(int value) {
    ui->outputWidget->setText(QString::number(value + ui->inputSpinBox1->value()));
}

Calculator::~Calculator() {
    delete ui;
}
