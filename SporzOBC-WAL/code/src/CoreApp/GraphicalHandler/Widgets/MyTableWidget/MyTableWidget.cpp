#include "CoreApp/IGraphicalHandler/IUiView/UiView/CalculatorForm/Calculator.hpp"
#include "CoreApp/IGraphicalHandler/Widgets/MyTableWidget/MyTableWidget.hpp"

MyTableWidget::MyTableWidget(QWidget *parent) : QTableView(parent) {
 setModel(new MyModel(parent));
}
