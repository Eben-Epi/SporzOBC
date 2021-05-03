/*!

\file DoctorsKillOrHealChoice.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_DOCTORS_KILL_OR_HEAL_CHOICE_HPP
#define SPORZOBC_WAL_DOCTORS_KILL_OR_HEAL_CHOICE_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class DoctorsKillOrHealChoice;
}

class DoctorsKillOrHealChoice final : public QWidget, public UiGameView, public RegisteredInFactory<DoctorsKillOrHealChoice>
{
Q_OBJECT

public:
    DoctorsKillOrHealChoice(QWidget *parent = nullptr);
    ~DoctorsKillOrHealChoice();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::DoctorsKillOrHealChoice *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_DOCTORS_KILL_OR_HEAL_CHOICE_HPP
