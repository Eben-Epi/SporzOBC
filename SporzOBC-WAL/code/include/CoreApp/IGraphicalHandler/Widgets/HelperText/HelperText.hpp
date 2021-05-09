/*!

\file HelperText.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_HELPERTEXT_HPP
#define SPORZOBC_WAL_HELPERTEXT_HPP

#include <QLabel>

class HelperText : public QLabel {
Q_OBJECT
public:
    explicit HelperText(QWidget * parent = nullptr) {};
    virtual ~HelperText() = default;
};

#endif //SPORZOBC_WAL_HELPERTEXT_HPP
