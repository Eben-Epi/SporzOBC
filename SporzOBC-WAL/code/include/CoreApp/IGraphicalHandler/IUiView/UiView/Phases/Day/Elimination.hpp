/*!

\file Elimination.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_ELIMINATION_HPP
#define SPORZOBC_WAL_ELIMINATION_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class Elimination;
}

class Elimination final : public QWidget, public UiGameView, public RegisteredInFactory<Elimination>
{
Q_OBJECT

public:
    Elimination(QWidget *parent = nullptr);
    ~Elimination();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::Elimination *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_ELIMINATION_HPP
