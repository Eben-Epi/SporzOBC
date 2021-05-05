/*!

\file MutantsKillOrMutateChoice.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_MUTANTS_KILL_OR_MUTATE_CHOICE_HPP
#define SPORZOBC_WAL_MUTANTS_KILL_OR_MUTATE_CHOICE_HPP

#include <QWidget>
#include <QAbstractButton>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class MutantsKillOrMutateChoice;
}

class MutantsKillOrMutateChoice final : public QWidget, public UiGameView, public RegisteredInFactory<MutantsKillOrMutateChoice>
{
Q_OBJECT

public:
    MutantsKillOrMutateChoice(QWidget *parent = nullptr);
    ~MutantsKillOrMutateChoice();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();
    void on_choice_buttonToggled(QAbstractButton *button, bool checked);

private:
    Ui::MutantsKillOrMutateChoice *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_MUTANTS_KILL_OR_MUTATE_CHOICE_HPP
