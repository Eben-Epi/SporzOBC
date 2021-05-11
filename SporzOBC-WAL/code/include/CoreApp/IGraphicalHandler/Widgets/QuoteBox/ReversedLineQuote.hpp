/*!

\file ReversedLineQuote.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_REVERSED_LINE_QUOTE_HPP
#define SPORZOBC_WAL_REVERSED_LINE_QUOTE_HPP

#include <QLabel>

class ReversedLineQuote : public QLabel {
Q_OBJECT
public:
    explicit ReversedLineQuote(QWidget * parent = nullptr) {};
    virtual ~ReversedLineQuote() = default;
};

#endif //SPORZOBC_WAL_REVERSED_LINE_QUOTE_HPP
