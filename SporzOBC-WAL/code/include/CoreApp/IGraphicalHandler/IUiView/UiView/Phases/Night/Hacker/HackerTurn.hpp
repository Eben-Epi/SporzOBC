/*!

\file HackerTurn.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_HACKER_TURN_HPP
#define SPORZOBC_WAL_HACKER_TURN_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class HackerTurn;
}

class HackerTurn final : public QWidget, public UiGameView, public RegisteredInFactory<HackerTurn>
{
Q_OBJECT

public:
    HackerTurn(QWidget *parent = nullptr);
    ~HackerTurn();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::HackerTurn *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_HACKER_TURN_HPP
