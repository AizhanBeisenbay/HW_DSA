#ifndef DATASOURCE_H
#define DATASOURCE_H

#include <QObject>
#include <QString>
#include <QVariant>
#include <QList>

class DataSource : public QObject
{
    Q_OBJECT
    QList<QObject*> m_dataItems;
public:
    explicit DataSource(QObject *parent = nullptr);

    Q_PROPERTY(QList<QObject*> dataItems MEMBER m_dataItems NOTIFY dataItemsChanged)

    void processData(QString x, QString y);
    void refreshData();

signals:
    void dataItemsChanged();
    void dataReady();


public slots:

};

#endif // DATASOURCE_H
