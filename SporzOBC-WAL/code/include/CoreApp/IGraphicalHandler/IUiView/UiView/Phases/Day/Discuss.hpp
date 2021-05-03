/*!

\file Discuss.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_DISCUSS_HPP
#define SPORZOBC_WAL_DISCUSS_HPP

#include <QWidget>
#include "CoreApp/IGraphicalHandler/IUiView/UiView/UiViewFactory/UiViewFactory.hpp"

namespace Ui {
    class Discuss;
}

class Discuss final : public QWidget, public UiGameView, public RegisteredInFactory<Discuss>
{
Q_OBJECT

public:
    Discuss(QWidget *parent = nullptr);
    ~Discuss();

    void showUi() final;
    void hideUi() final;

    static std::unique_ptr<IUiView> CreateMethod();
    static UiViews GetFactoryName();

private slots:
    void on_nextButton_clicked();

private:
    Ui::Discuss *ui;
    static bool s_registered;
};

#endif //SPORZOBC_WAL_DISCUSS_HPP
