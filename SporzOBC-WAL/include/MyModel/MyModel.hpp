#ifndef SPORZOBC_WAL_MYMODEL_HPP
#define SPORZOBC_WAL_MYMODEL_HPP

#include <QAbstractTableModel>

class MyModel : public QAbstractTableModel {
    Q_OBJECT
public:
    MyModel(QObject *Parent = nullptr);
    ~MyModel() = default;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
};

#endif //SPORZOBC_WAL_MYMODEL_HPP
