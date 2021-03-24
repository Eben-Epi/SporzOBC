/*!

\file RegisteredInFactory.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#ifndef SPORZOBC_WAL_REGISTEREDINFACTORY_HPP
#define SPORZOBC_WAL_REGISTEREDINFACTORY_HPP

template <typename T>
class RegisteredInFactory
{
public:
    RegisteredInFactory() {
        s_bRegistered;
        std::cout<< "AGYDG" << std::endl;
    }
protected:
    static bool s_bRegistered;
};

#endif //SPORZOBC_WAL_REGISTEREDINFACTORY_HPP
