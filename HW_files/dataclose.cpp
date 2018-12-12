#include "dataclose.h"
#include "dataitem.h"
#include "networkdownload.h"
#include <QString>

DataClose::DataClose(QObject *parent) : QObject(parent)
{

}

void DataClose::processData(QString x, QString y)
{
 QDateTime date = QDateTime::fromString(x, "yyyy-mm-dd");

 QDateTime xAxisValue;
 xAxisValue.setDate(QDate::fromString(x,"yyyy-MM-dd"));
 xAxisValue.toMSecsSinceEpoch();


         DataItem* newData = new DataItem(xAxisValue, y);
        m_dataItems.append(newData);

}
void DataClose::refreshData()
{
    emit dataCloseReady();
}
