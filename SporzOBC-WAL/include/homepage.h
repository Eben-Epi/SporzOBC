#ifndef HOMEPAGE_HPP
#define HOMEPAGE_HPP

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Homepage; }
QT_END_NAMESPACE

class Homepage : public QMainWindow
{
    Q_OBJECT

public:
    Homepage(QWidget *parent = nullptr);
    ~Homepage();

private:
    Ui::Homepage *ui;
};
#endif // HOMEPAGE_HPP
