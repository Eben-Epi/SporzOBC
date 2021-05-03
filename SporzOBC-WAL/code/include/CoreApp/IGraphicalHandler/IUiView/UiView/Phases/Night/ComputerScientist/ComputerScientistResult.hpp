/*!

\file ComputerScientistResult.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_COMPUTER_SCIENTIST_RESULT_HPP
#define SPORZOBC_WAL_COMPUTER_SCIENTIST_RESULT_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class ComputerScientistResult;
}

class ComputerScientistResult final : public QWidget, public UiGameView, public RegisteredInFactory<ComputerScientistResult>
{
Q_OBJECT

public:
    ComputerScientistResult(QWidget *parent = nullptr);
    ~ComputerScientistResult();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::ComputerScientistResult *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_COMPUTER_SCIENTIST_RESULT_HPP
