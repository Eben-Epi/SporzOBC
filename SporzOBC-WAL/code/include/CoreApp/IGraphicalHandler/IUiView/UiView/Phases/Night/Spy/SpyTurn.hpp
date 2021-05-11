/*!

\file SpyTurn.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PSY_TURN_HPP
#define SPORZOBC_WAL_PSY_TURN_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class SpyTurn;
}

class SpyTurn final : public QWidget, public UiGameView, public RegisteredInFactory<SpyTurn>
{
Q_OBJECT

public:
    SpyTurn(QWidget *parent = nullptr);
    ~SpyTurn();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::SpyTurn *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_PSY_TURN_HPP
