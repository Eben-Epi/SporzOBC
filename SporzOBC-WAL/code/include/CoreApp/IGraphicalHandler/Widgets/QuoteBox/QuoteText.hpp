/*!

\file QuoteText.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_QUOTE_TEXT_HPP
#define SPORZOBC_WAL_QUOTE_TEXT_HPP

#include <QLabel>

class QuoteText : public QLabel {
Q_OBJECT
public:
    explicit QuoteText(QWidget * parent = nullptr) {};
    virtual ~QuoteText() = default;
};

#endif //SPORZOBC_WAL_QUOTE_TEXT_HPP
