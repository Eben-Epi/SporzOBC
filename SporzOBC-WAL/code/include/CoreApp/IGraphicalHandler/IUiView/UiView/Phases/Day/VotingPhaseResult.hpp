/*!

\file VotingPhaseResult.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_VOTING_PHASE_RESULT_HPP
#define SPORZOBC_WAL_VOTING_PHASE_RESULT_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class VotingPhaseResult;
}

class VotingPhaseResult final : public QWidget, public UiGameView, public RegisteredInFactory<VotingPhaseResult>
{
Q_OBJECT

public:
    VotingPhaseResult(QWidget *parent = nullptr);
    ~VotingPhaseResult();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::VotingPhaseResult *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_VOTING_PHASE_RESULT_HPP
