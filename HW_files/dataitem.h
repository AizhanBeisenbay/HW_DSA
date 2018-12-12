#ifndef DATAITEM_H
#define DATAITEM_H

#include <QString>
#include <QObject>
#include <QVector>
#include <QDateTime>

class DataItem : public QObject
{

    Q_OBJECT
    QDateTime m_x;
    float m_y;
public:
    explicit DataItem(QObject *parent = nullptr);

    DataItem(QDateTime x, QString y){

        m_x = x;
        m_y = y.toFloat();

    }

    Q_PROPERTY(QDateTime x MEMBER m_x NOTIFY xValueChanged)
    Q_PROPERTY(float y MEMBER m_y NOTIFY yValueChanged)

signals:
    void xValueChanged();
    void yValueChanged();

public slots:
};

#endif // DATAITEM_H
