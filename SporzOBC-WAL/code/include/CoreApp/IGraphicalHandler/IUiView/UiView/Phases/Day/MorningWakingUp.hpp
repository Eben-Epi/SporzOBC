/*!

\file MorningWakingUp.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_MORNING_WAKING_UP_HPP
#define SPORZOBC_WAL_MORNING_WAKING_UP_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class MorningWakingUp;
}

class MorningWakingUp final : public QWidget, public UiGameView, public RegisteredInFactory<MorningWakingUp>
{
Q_OBJECT

public:
    MorningWakingUp(QWidget *parent = nullptr);
    ~MorningWakingUp();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::MorningWakingUp *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_MORNING_WAKING_UP_HPP
