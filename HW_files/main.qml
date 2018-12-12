import QtQuick 2.9
import QtQuick.Window 2.2

import QtCharts 2.2

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Monthly Adjusted Prices")


    Connections{
        target: openData
        onDataReady: {
            openData.dataItems.forEach(function(element){
                openSeries.append(element.x, element.y);
               if(element.x > xAxis.max)
                {
                    xAxis.max = element.x;
                }
                 if(element.x < xAxis.min)
                {
                    xAxis.min = element.x;
                }
                 if(element.y> yAxis.max)
                 {
                     yAxis.max = element.y;
                 }
                if(element.y< yAxis.min)
                {
                    yAxis.min = element.y;
                }
            });
        }
    }
    Connections{
        target: closeData
        onDataReady: {
           closeData.dataItems.forEach(function(element){
                closeSeries.append(element.x, element.y);
               if(element.x > xAxis.max)
                {
                    xAxis.max = element.x;
                }
                 if(element.x < xAxis.min)
                {
                    xAxis.min = element.x;
                }
                 if(element.y> yAxis.max)
                 {
                     yAxis.max = element.y;
                 }
                if(element.y< yAxis.min)
                {
                    yAxis.min = element.y;
                }
            });
        }
    }
    Connections{
        target: highData
        onDataReady: {
           highData.dataItems.forEach(function(element){
                highSeries.append(element.x, element.y);
               if(element.x > xAxis.max)
                {
                    xAxis.max = element.x;
                }
                 if(element.x < xAxis.min)
                {
                    xAxis.min = element.x;
                }
                 if(element.y> yAxis.max)
                 {
                     yAxis.max = element.y;
                 }
                if(element.y< yAxis.min)
                {
                    yAxis.min = element.y;
                }
            });
        }
    }
    Connections{
        target: lowData
        onDataReady: {
           lowData.dataItems.forEach(function(element){
                lowSeries.append(element.x, element.y);
               if(element.x > xAxis.max)
                {
                    xAxis.max = element.x;
                }
                 if(element.x < xAxis.min)
                {
                    xAxis.min = element.x;
                }
                 if(element.y> yAxis.max)
                 {
                     yAxis.max = element.y;
                 }
                if(element.y< yAxis.min)
                {
                    yAxis.min = element.y;
                }
            });
        }
    }
    ChartView{
        anchors.fill: parent

                LineSeries{
            name: "Open Price"
            id: openSeries
            axisX: xAxis
            axisY: yAxis
        }

                LineSeries{
            name: "Close Price"
            id: closeSeries
            axisX: xAxis
            axisY: yAxis
        }

                LineSeries{
            name: "High Price"
            id: highSeries
            axisX: xAxis
            axisY: yAxis
        }

                LineSeries{
            name: "Low Price"
            id: lowSeries
            axisX: xAxis
            axisY: yAxis
        }
    }

    DateTimeAxis {
        id: xAxis
        tickCount: 20
        visible: true
        labelsAngle: 90
        gridVisible: true
        format: "yyyy-MM"
        min: "2018-07-01"
        max: "2018-12-01"
        titleText: "Date"
    }


    ValueAxis{
        id: yAxis
        min: 0.000
        max: 1.000
        titleText: "Value"

    }
}
