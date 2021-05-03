/*!

\file DoctorsKillOrHealTarget.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_DOCTORS_KILL_OR_HEAL_TARGET_HPP
#define SPORZOBC_WAL_DOCTORS_KILL_OR_HEAL_TARGET_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class DoctorsKillOrHealTarget;
}

class DoctorsKillOrHealTarget final : public QWidget, public UiGameView, public RegisteredInFactory<DoctorsKillOrHealTarget>
{
Q_OBJECT

public:
    DoctorsKillOrHealTarget(QWidget *parent = nullptr);
    ~DoctorsKillOrHealTarget();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::DoctorsKillOrHealTarget *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_DOCTORS_KILL_OR_HEAL_TARGET_HPP
