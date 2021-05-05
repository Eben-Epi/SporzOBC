/*!

\file MutantsParalysisTarget.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_MUTANTS_PARALYSIS_TARGET_HPP
#define SPORZOBC_WAL_MUTANTS_PARALYSIS_TARGET_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class MutantsParalysisTarget;
}

class MutantsParalysisTarget final : public QWidget, public UiGameView, public RegisteredInFactory<MutantsParalysisTarget>
{
Q_OBJECT

public:
    MutantsParalysisTarget(QWidget *parent = nullptr);
    ~MutantsParalysisTarget();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();
    void fillComboBox();

private slots:
    void on_nextButton_clicked();
    void on_selectTarget_currentTextChanged(const QString&);

private:
    Ui::MutantsParalysisTarget *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_MUTANTS_PARALYSIS_TARGET_HPP
