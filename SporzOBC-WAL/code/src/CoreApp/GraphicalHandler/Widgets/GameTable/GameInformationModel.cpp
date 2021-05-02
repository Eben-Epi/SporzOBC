/*!

\file GameInformationModel.cpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/

#include <CoreApp/IGraphicalHandler/Widgets/GameTable/GameInformationModel.hpp>
#include <QTableView>

GameInformationModel::GameInformationModel(QObject *parent)
        : QAbstractTableModel(parent), GameUiWidget()
{
}

int GameInformationModel::rowCount(const QModelIndex &index) const
{
    return rows;
}

int GameInformationModel::columnCount(const QModelIndex &index) const
{
    return 3;
}

QVariant GameInformationModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    int row = index.row();
    int col = index.column();

    switch (role) {
        case Qt::DisplayRole:
            return modelData.at(index.row()).at(index.column()); // TODO remove intermediate data model
        case Qt::TextAlignmentRole:
            if (col == 0)
                return Qt::AlignLeft + Qt::AlignVCenter;
            else
                return Qt::AlignRight + Qt::AlignVCenter;
    }
    return QVariant();
}


Qt::ItemFlags GameInformationModel::flags(const QModelIndex &index) const
{
    return QAbstractTableModel::flags(index);
}

void GameInformationModel::init() {
    auto &glm = this->accessGLM();
    int playerCount = glm.getPlayerCount();
    for (int ID = 1; ID <= playerCount; ID++) {
        QList<QString> row_data;
        row_data.push_back(QString::fromUtf8(glm.getPlayerName(ID).c_str()));
        row_data.push_back(QString::fromUtf8(printableGenome(glm.getPlayerGenome(ID)).c_str()));
        row_data.push_back(QString::fromUtf8(printableRole(glm.getPlayerRole(ID)).c_str()));
        this->modelData.push_back(row_data);
        this->insertRow(rows);
    }
}

bool GameInformationModel::insertRows(int row, int count, const QModelIndex &parent) {
    beginInsertRows(parent, row, row + count - 1);
    rows += count;
    endInsertRows();
    return true;
}

std::string GameInformationModel::printableRole(Role role) {
    switch (role) {
        case (MUTANT):
            return "Mutant.e de base";
        case (DOCTOR):
            return "Docteur.e";
        case (COMPUTER_SCIENTIST):
            return "Informaticien.ne";
        case (GENETICIST):
            return "Généticien.ne";
        case (PSYCHOLOGIST):
            return "Psychologue";
        case (HACKER):
            return "Hackeur.se";
        case (NOVICE_HACKER):
            return "Hackeur.se novice";
        case (SPY):
            return "Espion.ne";
        case (PAINTER):
            return "Peintre";
        default:
            throw SporzException("A player was not assigned a correct role", "printableRole");
    }
}

std::string GameInformationModel::printableGenome(Genome genome) {
    switch (genome) {
        case(STANDARD):
            return "Standard";
        case(IMMUNE):
            return "Résistant";
        case (HOST):
            return "Hôte";
    }
}

QVariant GameInformationModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::TextAlignmentRole) {
        if (section == 0)
            return Qt::AlignLeft + Qt::AlignVCenter;
        else
            return Qt::AlignRight + Qt::AlignVCenter;
    }

    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return QStringLiteral("NOM");
            case 1:
                return QStringLiteral("GENOME");
            case 2:
                return QStringLiteral("ROLE");
        }
    }
    return QVariant();
}

void GameInformationModel::refreshAllTable() {
    auto &glm = this->accessGLM();
    int playerCount = glm.getPlayerCount();
    for (int ID = 1; ID <= playerCount; ID++) {
        this->modelData[ID - 1][1] = QString::fromUtf8(printableGenome(glm.getPlayerGenome(ID)).c_str());
        this->modelData[ID - 1][2] = QString::fromUtf8(printableRole(glm.getPlayerRole(ID)).c_str());
    }
    emit dataChanged(index(0,0), index(rows - 1, 2));
}
