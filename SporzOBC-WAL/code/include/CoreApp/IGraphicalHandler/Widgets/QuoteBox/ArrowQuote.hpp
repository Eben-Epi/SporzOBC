/*!

\file ArrowQuote.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_ARROW_QUOTE_HPP
#define SPORZOBC_WAL_ARROW_QUOTE_HPP

#include <QLabel>

class ArrowQuote : public QLabel {
Q_OBJECT
public:
    explicit ArrowQuote(QWidget * parent = nullptr) {};
    virtual ~ArrowQuote() = default;
};

#endif //SPORZOBC_WAL_ARROW_QUOTE_HPP
