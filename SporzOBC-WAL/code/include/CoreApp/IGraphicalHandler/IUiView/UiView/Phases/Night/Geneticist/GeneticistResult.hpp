/*!

\file GeneticistResult.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_GENETICIST_RESULT_HPP
#define SPORZOBC_WAL_GENETICIST_RESULT_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class GeneticistResult;
}

class GeneticistResult final : public QWidget, public UiGameView, public RegisteredInFactory<GeneticistResult>
{
Q_OBJECT

public:
    GeneticistResult(QWidget *parent = nullptr);
    ~GeneticistResult();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::GeneticistResult *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_GENETICIST_RESULT_HPP
