#include "networkdownload.h"
#include <QNetworkReply>
#include <QNetworkRequest>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

NetworkDownload::NetworkDownload(QObject *parent) : QObject(parent)
{
    manager = new QNetworkAccessManager();

    connect(manager,SIGNAL(finished(QNetworkReply*)),this,SLOT(managerGetFinished(QNetworkReply*)));
}


void NetworkDownload::downloadJSON(QString url)
{
    QUrl baseURL(url);
    QNetworkRequest request(baseURL);
    manager->get(request);
}

void NetworkDownload::managerGetFinished(QNetworkReply* reply)
{
    QByteArray rawdata = reply->readAll();

    decodeJSON(rawdata);

    qDebug()<<"download finished";
}

void NetworkDownload::decodeJSON(QByteArray rawData)
{
    QJsonDocument document = QJsonDocument::fromJson(rawData);
    QList<QPair<QString,QString>> graphValues;

    if(document.isEmpty())
    {
        qDebug()<<"Data is not valid.";
    }

        else if(document.isObject() == true)
        {
            QJsonObject rootObject = document.object();
             QPair<QString,  QString> dataItem;
             QJsonObject timeSeries = rootObject["Monthly Adjusted Time Series"].toObject();
            QStringList keys = timeSeries.keys();
            for (QString k : keys){
                QJsonObject dayValues = timeSeries[k].toObject();
               QString openValue =  dayValues["1. open"].toString();
                QString highValue =  dayValues["2. high"].toString();
              QString lowValue =  dayValues["3. low"].toString();
              QString closeValue =  dayValues["4. close"].toString();


                            dataOpen.processData(k,openValue);
                            dataClose.processData(k,closeValue);
                            dataHigh.processData(k,highValue);
                            dataLow.processData(k,lowValue);



            }
               qDebug()<<"Data retrieved";



            dataOpen.refreshData();
            dataClose.refreshData();
            dataLow.refreshData();
            dataHigh.refreshData();




}
}







