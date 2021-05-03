/*!

\file PsychologistTarget.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PSYCHOLOGIST_TARGET_HPP
#define SPORZOBC_WAL_PSYCHOLOGIST_TARGET_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class PsychologistTarget;
}

class PsychologistTarget final : public QWidget, public UiGameView, public RegisteredInFactory<PsychologistTarget>
{
Q_OBJECT

public:
    PsychologistTarget(QWidget *parent = nullptr);
    ~PsychologistTarget();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::PsychologistTarget *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_PSYCHOLOGIST_TARGET_HPP
