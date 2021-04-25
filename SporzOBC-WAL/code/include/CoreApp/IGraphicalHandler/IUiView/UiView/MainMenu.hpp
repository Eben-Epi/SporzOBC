/*!

\file MainMenu.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_MAINMENU_HPP
#define SPORZOBC_WAL_MAINMENU_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class MainMenu;
}

class MainMenu final : public QWidget, public IUiView, public RegisteredInFactory<MainMenu>
{
Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();


private slots:
    void on_playButton_clicked();
    void on_quitButton_clicked();

private:
    Ui::MainMenu *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_MAINMENU_HPP
