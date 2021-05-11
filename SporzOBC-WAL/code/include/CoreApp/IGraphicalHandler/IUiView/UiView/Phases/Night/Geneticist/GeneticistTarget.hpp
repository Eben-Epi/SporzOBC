/*!

\file GeneticistTarget.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_GENETICIST_TARGET_HPP
#define SPORZOBC_WAL_GENETICIST_TARGET_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class GeneticistTarget;
}

class GeneticistTarget final : public QWidget, public UiGameView, public RegisteredInFactory<GeneticistTarget>
{
Q_OBJECT

public:
    GeneticistTarget(QWidget *parent = nullptr);
    ~GeneticistTarget();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::GeneticistTarget *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_GENETICIST_TARGET_HPP
