/*!

\file GameHistoryManager.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_GAMEHISTORYMANAGER_HPP
#define SPORZOBC_WAL_GAMEHISTORYMANAGER_HPP

#include <QtCore/QFile>
#include <QtCore/qtextstream.h>

class GameHistoryManager {
public:
    GameHistoryManager();
    ~GameHistoryManager();

    QTextStream &out();
private:
    std::unique_ptr<QFile> logFile;
    std::unique_ptr<QTextStream> streamFileOut;
};

#endif //SPORZOBC_WAL_GAMEHISTORYMANAGER_HPP
