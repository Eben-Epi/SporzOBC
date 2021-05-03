/*!

\file MutantsRecap.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_MUTANTS_RECAP_HPP
#define SPORZOBC_WAL_MUTANTS_RECAP_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class MutantsRecap;
}

class MutantsRecap final : public QWidget, public UiGameView, public RegisteredInFactory<MutantsRecap>
{
Q_OBJECT

public:
    MutantsRecap(QWidget *parent = nullptr);
    ~MutantsRecap();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::MutantsRecap *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_MUTANTS_RECAP_HPP
