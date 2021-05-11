/*!

\file MutantsTurn.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_MUTANTS_TURN_HPP
#define SPORZOBC_WAL_MUTANTS_TURN_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class MutantsTurn;
}

class MutantsTurn final : public QWidget, public UiGameView, public RegisteredInFactory<MutantsTurn>
{
Q_OBJECT

public:
    MutantsTurn(QWidget *parent = nullptr);
    ~MutantsTurn();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::MutantsTurn *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_MUTANTS_TURN_HPP
