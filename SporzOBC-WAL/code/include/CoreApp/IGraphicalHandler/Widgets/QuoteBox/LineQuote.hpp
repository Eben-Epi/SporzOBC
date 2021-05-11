/*!

\file LineQuote.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_LINE_QUOTE_HPP
#define SPORZOBC_WAL_LINE_QUOTE_HPP

#include <QLabel>

class LineQuote : public QLabel {
Q_OBJECT
public:
    explicit LineQuote(QWidget * parent = nullptr) {};
    virtual ~LineQuote() = default;
};

#endif //SPORZOBC_WAL_LINE_QUOTE_HPP
