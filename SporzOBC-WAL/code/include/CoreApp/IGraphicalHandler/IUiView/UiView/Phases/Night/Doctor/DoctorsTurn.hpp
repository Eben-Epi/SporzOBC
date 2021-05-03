/*!

\file DoctorsTurn.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_DOCTORS_TURN_HPP
#define SPORZOBC_WAL_DOCTORS_TURN_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class DoctorsTurn;
}

class DoctorsTurn final : public QWidget, public UiGameView, public RegisteredInFactory<DoctorsTurn>
{
Q_OBJECT

public:
    DoctorsTurn(QWidget *parent = nullptr);
    ~DoctorsTurn();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::DoctorsTurn *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_DOCTORS_TURN_HPP
