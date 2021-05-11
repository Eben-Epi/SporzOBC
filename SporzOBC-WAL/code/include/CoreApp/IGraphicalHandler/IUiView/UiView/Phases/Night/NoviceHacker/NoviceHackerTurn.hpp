/*!

\file NoviceHackerTurn.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_NOVICE_HACKER_TURN_HPP
#define SPORZOBC_WAL_NOVICE_HACKER_TURN_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class NoviceHackerTurn;
}

class NoviceHackerTurn final : public QWidget, public UiGameView, public RegisteredInFactory<NoviceHackerTurn>
{
Q_OBJECT

public:
    NoviceHackerTurn(QWidget *parent = nullptr);
    ~NoviceHackerTurn();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::NoviceHackerTurn *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_NOVICE_HACKER_TURN_HPP
