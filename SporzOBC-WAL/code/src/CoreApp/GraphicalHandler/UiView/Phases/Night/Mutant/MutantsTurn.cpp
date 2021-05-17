/*!

\file MutantsTurn.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <iostream>
#include <QtGlobal>
#include <QFile>
#include <QDebug>
#ifdef Q_OS_ANDROID
#include <QAndroidJniObject>
#include <QStandardPaths>
#endif
#include <CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp>
#include <CoreApp/IGraphicalHandler/GraphicalHandler/GraphicalHandler.hpp>
#include <QtCore/qtextstream.h>
#include "./Phases/Night/Mutant/ui_turn.h"
#include "CoreApp/IGraphicalHandler/IUiView/UiView/Phases/Night/Mutant/MutantsTurn.hpp"

MutantsTurn::MutantsTurn(QWidget *parent)
        : QWidget(parent), ui(new Ui::MutantsTurn), RegisteredInFactory<MutantsTurn>()
{
    ui->setupUi(this);
#ifndef Q_OS_ANDROID
    this->showMaximized();
#endif
}

void MutantsTurn::showUi() {
    this->setStyleSheet(static_cast<GraphicalHandler*>(&this->accessGH())->getGlobalStyleSheet());
    auto aliveMutants = this->accessGLM().getAlivePlayersAssociatedWithRole(MUTANT);
    std::string labelText;
    if (aliveMutants.size() > 1 && this->accessGLM().isTurnPassed(MUTANT)) {
        labelText += "Les mutants en vie sont : ";
        for (auto player = aliveMutants.begin(); player != aliveMutants.end(); ++player) {
            if (player != aliveMutants.begin())
                labelText += (std::next(player) == aliveMutants.end() ? " et " : ", ") + player.operator*()->getUserName();
            else
                labelText += player.operator*()->getUserName();
        }
        labelText += ".";
    } else
        labelText += "Le mutant de base nommé " + aliveMutants[0]->getUserName() + " se réveille.";
    this->ui->aliveMutants->setText(labelText.c_str());
    this->show();
}

MutantsTurn::~MutantsTurn() {
    delete ui;
}

std::unique_ptr<IUiView> MutantsTurn::CreateMethod() {
    return std::make_unique<MutantsTurn>();
}

UiViews MutantsTurn::GetFactoryName() {
    return MUTANTS_TURN;
}

void MutantsTurn::hideUi() {
    this->hide();
}

void MutantsTurn::on_nextNightButton_clicked() {
#ifdef Q_OS_ANDROID
    QAndroidJniObject::callStaticMethod<void>("org/sporz/example/Vibration/VibrationClient", "start", "(I)V", 300);
#endif
#ifdef Q_OS_ANDROID
    QString fichier = QStandardPaths::writableLocation(QStandardPaths::DownloadLocation) + "/Monfichier.txt";
    qDebug() << fichier;
#else
    QString fichier = "monFichier.txt";
#endif

    QFile file(fichier); // Appel du constructeur de la classe QFile

    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Append)) {
// Si l'ouverture du fichier en écriture à réussie

// écrire dans le fichier en utilisant un flux :
        QTextStream out(&file);
        out << "La valeur approchée de pi est : " << 3.15 << "\n";

// Fermer le fichier
        file.close();
    }
    if (!this->accessGLM().isTurnPassed(MUTANT)) {
        this->accessGLM().setTurnPassed(MUTANT);
        this->accessGH().loadUiGameView(MUTANTS_KILL_OR_MUTATE_CHOICE);
        this->accessGH().changeUiView(MUTANTS_KILL_OR_MUTATE_CHOICE);
    } else {
        this->accessGH().loadUiGameView(MUTANTS_RECAP);
        this->accessGH().changeUiView(MUTANTS_RECAP);
    }
}
