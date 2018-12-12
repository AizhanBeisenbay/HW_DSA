#ifndef DATACLOSE_H
#define DATACLOSE_H


#include <QObject>
#include <QString>
#include <QVariant>
#include <QList>

class DataClose : public QObject
{
    Q_OBJECT
    QList<QObject*> m_dataItems;
public:
    explicit DataClose(QObject *parent = nullptr);

    Q_PROPERTY(QList<QObject*> dataItems MEMBER m_dataItems NOTIFY dataItemsChanged)

    void processData(QString x, QString y);
    void refreshData();

signals:
    void dataItemsChanged();
    void dataCloseReady();


public slots:

};



#endif // DATACLOSE_H
