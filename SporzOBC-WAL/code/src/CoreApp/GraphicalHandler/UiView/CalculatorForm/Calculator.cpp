#include <iostream>
#include "./ui_calculatorform.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/CalculatorForm/Calculator.hpp"

Calculator::Calculator(QWidget *parent)
        : QWidget(parent), ui(new Ui::CalculatorForm), RegisteredInFactory<Calculator>()
{
    ui->setupUi(this);
}

void Calculator::on_inputSpinBox1_valueChanged(int value) {
    ui->outputWidget->setText(QString::number(value + ui->inputSpinBox2->value()));

}

void Calculator::on_inputSpinBox2_valueChanged(int value) {
    ui->outputWidget->setText(QString::number(value + ui->inputSpinBox1->value()));
}

void Calculator::showUi() {
    qDebug("debuggies");
    this->show();
}

Calculator::~Calculator() {
    delete ui;
}

std::unique_ptr<IUiView> Calculator::CreateMethod() {
    return std::make_unique<Calculator>();
}

UiViews Calculator::GetFactoryName() {
    return CALCULATOR;
}
