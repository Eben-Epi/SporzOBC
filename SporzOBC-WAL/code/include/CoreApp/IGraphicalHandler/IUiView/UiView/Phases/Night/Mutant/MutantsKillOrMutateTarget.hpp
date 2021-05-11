/*!

\file MutantsKillOrMutateTarget.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_MUTANTS_KILL_OR_MUTATE_TARGET_HPP
#define SPORZOBC_WAL_MUTANTS_KILL_OR_MUTATE_TARGET_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class MutantsKillOrMutateTarget;
}

class MutantsKillOrMutateTarget final : public QWidget, public UiGameView, public RegisteredInFactory<MutantsKillOrMutateTarget>
{
Q_OBJECT

public:
    MutantsKillOrMutateTarget(QWidget *parent = nullptr);
    ~MutantsKillOrMutateTarget();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

    void fillComboBox();

private slots:
    void on_nextNightButton_clicked();
    void on_selectTarget_currentTextChanged(const QString&);

private:
    Ui::MutantsKillOrMutateTarget *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_MUTANTS_KILL_OR_MUTATE_TARGET_HPP
