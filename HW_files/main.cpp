#include <QApplication>
#include <QQmlApplicationEngine>
#include "networkdownload.h"
#include "datasource.h"

#include <QQmlContext>
#include <QVariant>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    NetworkDownload downloader;

    QQmlContext* rootCtx = engine.rootContext();

     rootCtx->setContextProperty("openData",&downloader.dataOpen);
     rootCtx->setContextProperty("closeData",&downloader.dataClose);
     rootCtx->setContextProperty("highData",&downloader.dataHigh);
     rootCtx->setContextProperty("lowData",&downloader.dataLow);

    downloader.downloadJSON("https://www.alphavantage.co/query?function=TIME_SERIES_MONTHLY_ADJUSTED&symbol=MSFT&apikey=demo");
    //DataSource burstData;




    return app.exec();
}
