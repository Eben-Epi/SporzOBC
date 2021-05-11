/*!

\file PainterResult.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PAINTER_RESULT_HPP
#define SPORZOBC_WAL_PAINTER_RESULT_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class PainterResult;
}

class PainterResult final : public QWidget, public UiGameView, public RegisteredInFactory<PainterResult>
{
Q_OBJECT

public:
    PainterResult(QWidget *parent = nullptr);
    ~PainterResult();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::PainterResult *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_PAINTER_RESULT_HPP
