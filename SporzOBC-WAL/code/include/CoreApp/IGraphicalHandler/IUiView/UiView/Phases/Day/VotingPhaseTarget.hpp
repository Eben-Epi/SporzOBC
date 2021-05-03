/*!

\file VotingPhaseTarget.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_VOTING_0PHASE_TARGET_HPP
#define SPORZOBC_WAL_VOTING_0PHASE_TARGET_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class VotingPhaseTarget;
}

class VotingPhaseTarget final : public QWidget, public UiGameView, public RegisteredInFactory<VotingPhaseTarget>
{
Q_OBJECT

public:
    VotingPhaseTarget(QWidget *parent = nullptr);
    ~VotingPhaseTarget();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::VotingPhaseTarget *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_VOTING_0PHASE_TARGET_HPP
