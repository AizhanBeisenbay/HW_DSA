#include "datasource.h"
#include "dataitem.h"
#include "networkdownload.h"
#include <QString>

DataSource::DataSource(QObject *parent) : QObject(parent)
{

}

void DataSource::processData(QString x, QString y)
{
 QDateTime date = QDateTime::fromString(x, "yyyy-mm-dd");

 QDateTime xAxisValue;
 xAxisValue.setDate(QDate::fromString(x,"yyyy-MM-dd"));
 xAxisValue.toMSecsSinceEpoch();


         DataItem* newData = new DataItem(xAxisValue, y);
        m_dataItems.append(newData);
       // qDebug() << "Value: " <<y;
      //qDebug() << "Days from startDate to endDate: " << startDate.daysTo(date);
}

void DataSource::refreshData()
{
    emit dataReady();
}
