/*!

\file VotingPhaseEnd.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_VOTING_PHASE_END_HPP
#define SPORZOBC_WAL_VOTING_PHASE_END_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class VotingPhaseEnd;
}

class VotingPhaseEnd final : public QWidget, public UiGameView, public RegisteredInFactory<VotingPhaseEnd>
{
Q_OBJECT

public:
    VotingPhaseEnd(QWidget *parent = nullptr);
    ~VotingPhaseEnd();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::VotingPhaseEnd *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_VOTING_PHASE_END_HPP
