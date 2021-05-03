/*!

\file PsychologistTurn.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PSYCHOLOGIST_TURN_HPP
#define SPORZOBC_WAL_PSYCHOLOGIST_TURN_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class PsychologistTurn;
}

class PsychologistTurn final : public QWidget, public UiGameView, public RegisteredInFactory<PsychologistTurn>
{
Q_OBJECT

public:
    PsychologistTurn(QWidget *parent = nullptr);
    ~PsychologistTurn();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::PsychologistTurn *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_PSYCHOLOGIST_TURN_HPP
