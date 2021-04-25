/*!

\file SporzException.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_SPORZEXCEPTION_HPP
#define SPORZOBC_WAL_SPORZEXCEPTION_HPP

#include <exception>
#include <string>
#include <utility>

class SporzException : public std::exception {
public:
    const char * what () const throw ()
    {
        return _exceptionMessage.c_str();
    }
    SporzException(const std::string& msg, const std::string&  funcName, const std::string& exceptionType = "SporzException")
    : std::exception(), _exceptionMessage(exceptionType + " in function " + funcName + "(): " + msg) {}
protected:
    std::string _exceptionMessage;
};

#endif //SPORZOBC_WAL_SPORZEXCEPTION_HPP
