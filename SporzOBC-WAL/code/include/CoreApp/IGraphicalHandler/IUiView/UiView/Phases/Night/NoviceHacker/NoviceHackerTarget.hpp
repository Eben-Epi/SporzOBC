/*!

\file NoviceHackerTarget.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_NOVICE_HACKER_TARGET_HPP
#define SPORZOBC_WAL_NOVICE_HACKER_TARGET_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class NoviceHackerTarget;
}

class NoviceHackerTarget final : public QWidget, public UiGameView, public RegisteredInFactory<NoviceHackerTarget>
{
Q_OBJECT

public:
    NoviceHackerTarget(QWidget *parent = nullptr);
    ~NoviceHackerTarget();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextNightButton_clicked();

private:
    Ui::NoviceHackerTarget *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_NOVICE_HACKER_TARGET_HPP
