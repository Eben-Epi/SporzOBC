/*!

\file GameHistoryManager.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <QtGlobal>
#ifdef Q_OS_ANDROID
#include <QStandardPaths>
#endif

#include <QtCore/QString>
#include "CoreApp/GameLogicManager/GameHistoryManager.hpp"

GameHistoryManager::GameHistoryManager() {
#ifdef Q_OS_ANDROID
QString filepath = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation) + "/SporzLog.txt";
#else
    QString filepath = "SporzLog.txt";
#endif

    this->logFile = std::make_unique<QFile>(filepath); // Appel du constructeur de la classe QFile

    if (!logFile->open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append))
        throw std::runtime_error("Can't access file SporzLog.txt");

    this->streamFileOut = std::make_unique<QTextStream>(this->logFile.get());
    this->streamFileOut->setCodec("ISO 8859-1");
}

GameHistoryManager::~GameHistoryManager() {
    this->logFile->close();
}

QTextStream &GameHistoryManager::out() {
    return *this->streamFileOut;
}

