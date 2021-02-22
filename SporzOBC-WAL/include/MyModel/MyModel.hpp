#ifndef SPORZOBC_WAL_MYMODEL_HPP
#define SPORZOBC_WAL_MYMODEL_HPP

#include <QString>
#include <QAbstractTableModel>

const int COLS= 3;
const int ROWS= 2;

class MyModel : public QAbstractTableModel {
    Q_OBJECT
public:
    MyModel(QObject *Parent = nullptr);
    ~MyModel() = default;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
private:
    QString m_gridData[ROWS][COLS];  //holds text entered into QTableView
signals:
    void editCompleted(const QString &);
};

#endif //SPORZOBC_WAL_MYMODEL_HPP
