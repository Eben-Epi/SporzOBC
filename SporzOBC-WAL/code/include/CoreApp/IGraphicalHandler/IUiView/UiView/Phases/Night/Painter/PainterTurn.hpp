/*!

\file PainterTurn.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PAINTER_TURN_HPP
#define SPORZOBC_WAL_PAINTER_TURN_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class PainterTurn;
}

class PainterTurn final : public QWidget, public UiGameView, public RegisteredInFactory<PainterTurn>
{
Q_OBJECT

public:
    PainterTurn(QWidget *parent = nullptr);
    ~PainterTurn();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::PainterTurn *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_PAINTER_TURN_HPP
