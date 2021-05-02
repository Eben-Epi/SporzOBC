/*!

\file GameInformationModel.hpp
\brief Enter your brief here //TODO
\author Eben
\version 0.1

*/
#ifndef SPORZOBC_WAL_GAMEINFORMATIONMODEL_HPP
#define SPORZOBC_WAL_GAMEINFORMATIONMODEL_HPP

#include <QString>
#include <QAbstractTableModel>
#include "CoreApp/IGraphicalHandler/Widgets/GameUiModel/GameUiWidget.hpp"

class GameInformationModel : public QAbstractTableModel, public GameUiWidget {
Q_OBJECT
public:
    explicit GameInformationModel(QObject *Parent = nullptr);
    ~GameInformationModel() override = default;

    void init();
    int rowCount(const QModelIndex &index) const override;
    int columnCount(const QModelIndex &index) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const override;

    bool insertRows(int row, int count, const QModelIndex &parent) override;

    void refreshAllTable();
private:
    std::string printableGenome(Genome);
    std::string printableRole(Role);
    int rows = 0;
    QList<QList<QString>> modelData;
};

#endif //SPORZOBC_WAL_GAMEINFORMATIONMODEL_HPP
