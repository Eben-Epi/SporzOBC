#ifndef SPORZOBC_WAL_MYMODEL_HPP
#define SPORZOBC_WAL_MYMODEL_HPP

#include <QTimer>
#include <QTime>
#include <QAbstractTableModel>

class MyModel : public QAbstractTableModel {
    Q_OBJECT
public:
    MyModel(QObject *Parent = nullptr);
    ~MyModel() = default;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

        private:
    QTimer *timer;
private slots:
    void timerHit();
};

#endif //SPORZOBC_WAL_MYMODEL_HPP
