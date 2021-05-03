/*!

\file NoviceHackerResult.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_NOVICE_HACKER_RESULT_HPP
#define SPORZOBC_WAL_NOVICE_HACKER_RESULT_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class NoviceHackerResult;
}

class NoviceHackerResult final : public QWidget, public UiGameView, public RegisteredInFactory<NoviceHackerResult>
{
Q_OBJECT

public:
    NoviceHackerResult(QWidget *parent = nullptr);
    ~NoviceHackerResult();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::NoviceHackerResult *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_NOVICE_HACKER_RESULT_HPP
