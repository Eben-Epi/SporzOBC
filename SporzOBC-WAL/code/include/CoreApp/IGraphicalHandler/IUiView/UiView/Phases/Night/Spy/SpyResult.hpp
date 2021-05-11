/*!

\file SpyResult.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PSY_RESULT_HPP
#define SPORZOBC_WAL_PSY_RESULT_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class SpyResult;
}

class SpyResult final : public QWidget, public UiGameView, public RegisteredInFactory<SpyResult>
{
Q_OBJECT

public:
    SpyResult(QWidget *parent = nullptr);
    ~SpyResult();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::SpyResult *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_PSY_RESULT_HPP
