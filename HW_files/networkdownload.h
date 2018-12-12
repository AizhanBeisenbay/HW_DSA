#ifndef NETWORKDOWNLOAD_H
#define NETWORKDOWNLOAD_H


#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include "datasource.h"


class NetworkDownload : public QObject
{
    Q_OBJECT

    QNetworkAccessManager* manager;

public:
    explicit NetworkDownload(QObject *parent = nullptr);
    DataSource dataOpen;
    DataSource dataClose;
    DataSource dataHigh;
    DataSource dataLow;
signals:

public slots:

    //download file
    void downloadJSON(QString url);

    //finish network interaction
    void managerGetFinished(QNetworkReply* reply);

private:
    //Helper function for decoding JSON data
    void decodeJSON(QByteArray rawData);
};
#endif // NETWORKDOWNLOAD_H
