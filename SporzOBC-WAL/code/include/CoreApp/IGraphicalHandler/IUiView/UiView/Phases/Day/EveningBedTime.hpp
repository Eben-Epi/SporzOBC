/*!

\file EveningBedTime.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_EVENING_BED_TIME_HPP
#define SPORZOBC_WAL_EVENING_BED_TIME_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class EveningBedTime;
}

class EveningBedTime final : public QWidget, public UiGameView, public RegisteredInFactory<EveningBedTime>
{
Q_OBJECT

public:
    EveningBedTime(QWidget *parent = nullptr);
    ~EveningBedTime();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::EveningBedTime *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_EVENING_BED_TIME_HPP
