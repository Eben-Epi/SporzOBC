/*!

\file GameInformation.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_GAMEINFORMATION_HPP
#define SPORZOBC_WAL_GAMEINFORMATION_HPP

#include <QWidget>
#include <CoreApp/IGraphicalHandler/IUiView/IUiView.hpp>

#include <QStandardItem>

namespace Ui {
    class GameInformation;
}

class GameInformation : public QWidget, public UiGameView, public RegisteredInFactory<GameInformation> {
    Q_OBJECT

public:
    GameInformation(QWidget *parent = nullptr);
    ~GameInformation();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

    Ui::GameInformation *ui;

private slots:
    void on_randGenomes_clicked();
    void on_randRoles_clicked();
    void on_nextButton_clicked();
private:
    static bool s_registered;
};


#endif //SPORZOBC_WAL_GAMEINFORMATION_HPP
