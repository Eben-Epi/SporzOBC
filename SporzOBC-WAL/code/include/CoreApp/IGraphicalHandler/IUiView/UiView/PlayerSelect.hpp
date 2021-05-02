/*!

\file PlayerSelect.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_PLAYERSELECT_HPP
#define SPORZOBC_WAL_PLAYERSELECT_HPP

#include <QWidget>
#include <CoreApp/IGraphicalHandler/IUiView/IUiView.hpp>
#include <QListWidget>

namespace Ui {
    class PlayerSelect;
}

class PlayerSelect : public QWidget, public UiGameView, public RegisteredInFactory<PlayerSelect> {
Q_OBJECT

public:
    PlayerSelect(QWidget *parent = nullptr);
    ~PlayerSelect();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

    Ui::PlayerSelect *ui;

private slots:
    void on_playerNameList_itemChanged(QListWidgetItem *);
    void on_playerCountSpinBox_valueChanged(int);
    void on_nextButton_clicked();

private:
    static bool s_registered;
};

#endif //SPORZOBC_WAL_PLAYERSELECT_HPP
