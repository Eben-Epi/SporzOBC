/*!

\file PainterTarget.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PAINTER_TARGET_HPP
#define SPORZOBC_WAL_PAINTER_TARGET_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class PainterTarget;
}

class PainterTarget final : public QWidget, public UiGameView, public RegisteredInFactory<PainterTarget>
{
Q_OBJECT

public:
    PainterTarget(QWidget *parent = nullptr);
    ~PainterTarget();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::PainterTarget *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_PAINTER_TARGET_HPP
