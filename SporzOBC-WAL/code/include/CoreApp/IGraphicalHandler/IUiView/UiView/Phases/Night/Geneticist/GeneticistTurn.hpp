/*!

\file GeneticistTurn.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_GENETICIST_TURN_HPP
#define SPORZOBC_WAL_GENETICIST_TURN_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class GeneticistTurn;
}

class GeneticistTurn final : public QWidget, public UiGameView, public RegisteredInFactory<GeneticistTurn>
{
Q_OBJECT

public:
    GeneticistTurn(QWidget *parent = nullptr);
    ~GeneticistTurn();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::GeneticistTurn *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_GENETICIST_TURN_HPP
