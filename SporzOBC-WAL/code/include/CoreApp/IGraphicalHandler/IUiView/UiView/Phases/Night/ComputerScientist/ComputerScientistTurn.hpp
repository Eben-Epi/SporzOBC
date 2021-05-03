/*!

\file ComputerScientistTurn.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_COMPUTER_SCIENTIST_TURN_HPP
#define SPORZOBC_WAL_COMPUTER_SCIENTIST_TURN_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class ComputerScientistTurn;
}

class ComputerScientistTurn final : public QWidget, public UiGameView, public RegisteredInFactory<ComputerScientistTurn>
{
Q_OBJECT

public:
    ComputerScientistTurn(QWidget *parent = nullptr);
    ~ComputerScientistTurn();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::ComputerScientistTurn *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_COMPUTER_SCIENTIST_TURN_HPP
