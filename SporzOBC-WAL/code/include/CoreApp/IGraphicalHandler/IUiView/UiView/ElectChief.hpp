/*!

\file ElectChief.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_ELECTCHIEF_HPP
#define SPORZOBC_WAL_ELECTCHIEF_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class ElectChief;
}

class ElectChief final : public QWidget, public UiGameView, public RegisteredInFactory<ElectChief>
{
Q_OBJECT

public:
    ElectChief(QWidget *parent = nullptr);
    ~ElectChief();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

    void fillComboBox();

private slots:
    void on_nextButton_clicked();
    void on_selectChief_currentIndexChanged(int index);


private:
    Ui::ElectChief *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_ELECTCHIEF_HPP
