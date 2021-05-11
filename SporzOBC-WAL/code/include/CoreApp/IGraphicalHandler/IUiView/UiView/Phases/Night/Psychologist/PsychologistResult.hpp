/*!

\file PsychologistResult.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PSYCHOLOGIST_RESULT_HPP
#define SPORZOBC_WAL_PSYCHOLOGIST_RESULT_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class PsychologistResult;
}

class PsychologistResult final : public QWidget, public UiGameView, public RegisteredInFactory<PsychologistResult>
{
Q_OBJECT

public:
    PsychologistResult(QWidget *parent = nullptr);
    ~PsychologistResult();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::PsychologistResult *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_PSYCHOLOGIST_RESULT_HPP
