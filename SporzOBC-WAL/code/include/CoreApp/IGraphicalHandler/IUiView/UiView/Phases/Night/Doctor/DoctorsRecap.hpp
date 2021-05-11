/*!

\file DoctorsRecap.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_DOCTORS_RECAP_HPP
#define SPORZOBC_WAL_DOCTORS_RECAP_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class DoctorsRecap;
}

class DoctorsRecap final : public QWidget, public UiGameView, public RegisteredInFactory<DoctorsRecap>
{
Q_OBJECT

public:
    DoctorsRecap(QWidget *parent = nullptr);
    ~DoctorsRecap();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::DoctorsRecap *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_DOCTORS_RECAP_HPP
