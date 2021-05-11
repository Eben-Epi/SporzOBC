/*!

\file HackerTarget.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_HACKER_TARGET_HPP
#define SPORZOBC_WAL_HACKER_TARGET_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class HackerTarget;
}

class HackerTarget final : public QWidget, public UiGameView, public RegisteredInFactory<HackerTarget>
{
Q_OBJECT

public:
    HackerTarget(QWidget *parent = nullptr);
    ~HackerTarget();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::HackerTarget *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_HACKER_TARGET_HPP
