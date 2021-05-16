/*!

\file ComputerScientistTurnImg.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_COMPUTER_SCIENTIST_TURNIMG_HPP
#define SPORZOBC_WAL_COMPUTER_SCIENTIST_TURNIMG_HPP

#include <QLabel>
#include <QResizeEvent>
#include <QApplication>

class ComputerScientistTurnImg : public QLabel {
Q_OBJECT
public:
    explicit ComputerScientistTurnImg(QWidget * parent = nullptr) {};
    virtual ~ComputerScientistTurnImg() = default;

    void aspectRatioCenter() {
        if(this->size().width() > this->size().height()){
            this->resize(this->size().height(),this->size().height());
        }else{
            this->resize(this->size().width(),this->size().width());
        }
        this->move(this->window()->width() / 2 - this->width() / 2, this->y());
    }

    void resizeEvent(QResizeEvent *event) override {
        aspectRatioCenter();
        this->update();
    }

    void paintEvent(QPaintEvent *event) override {
        aspectRatioCenter();
    }

private:
    int myWidgetX;
};

#endif //SPORZOBC_WAL_COMPUTER_SCIENTIST_TURNIMG_HPP
