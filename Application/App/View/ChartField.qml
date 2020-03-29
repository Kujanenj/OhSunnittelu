import QtQuick 2.0
import QtQuick.Controls 2.13
import QtCharts 2.3
import QtQuick.Window 2.12

/**
  * represents charts tab in the UI
 */


Item {
    Frame {
        id: frame
        anchors.fill: parent

        ChartView {
            title: "Matkan parhaat hiihtäjät ja niiden ajat"
            antialiasing: true
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.right: parent.horizontalCenter
            anchors.bottom: parent.verticalCenter
            id: linechart
            Button{
                width: 100
                height : 50
                onClicked: {
                    var test = DataController.someData()
                     series.clear();

                    series.append(1,1)
                    series.append(test,2)
                }

            }

            LineSeries {
                id: series
                name: "Ajat"
                axisX: CategoryAxis{
                    min: 0
                    max: 6

                    CategoryRange {
                        label: "Äijä"
                        endValue: 1
                        }
                    CategoryRange {
                        label: "Matti"
                        endValue: 2
                        }
                    CategoryRange {
                        label: "Erkki"
                        endValue: 3
                        }
                    CategoryRange {
                        label: "Jussi"
                        endValue: 4
                        }
                    CategoryRange {
                        label: "Mastiff"
                        endValue: 5
                        }
                    CategoryRange {
                        label: "Joku"
                        endValue: 6
                    }

                }
                axisY: CategoryAxis{
                    min: 1
                    max: 7.5

                    CategoryRange{
                        label: "2:00:00"
                        endValue: 3
                    }
                    CategoryRange{
                        label: "3:00:00"
                        endValue: 4
                    }
                    CategoryRange{
                        label: "4:00:00"
                        endValue: 5
                    }
                    CategoryRange{
                        label: "5:00:00"
                        endValue: 6
                    }
                    CategoryRange{
                        label: "6:00:00"
                        endValue: 7
                    }
                }

                XYPoint {id: first; x: 0.5; y: 2.0 }
                XYPoint {id: second; x: 1.5; y: 2.3 }
                XYPoint { x: 2.5; y: 2.5 }
                XYPoint { x: 3.5; y: 3.4 }
                XYPoint { x: 4.5; y: 5.1 }
                XYPoint { x: 5.5; y: 6.0 }

            }
        }
        ChartView {
            title: "Osallistujat eri matkoille suhteessa"
            theme: ChartView.ChartThemeBlueIcy
            antialiasing: true
            anchors.left: parent.horizontalCenter
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: parent.verticalCenter

            PieSeries {
                id: osallistujat
                PieSlice { label: "P50"; value: 24.9 }
                PieSlice { label: "P30"; value: 5.1 }
                PieSlice { label: "V50"; value: 70.0 }
            }
        }
        ChartView {
            title: "Urheilijoiden jakauma maittain"
            width: 625
            height: 325
            theme: ChartView.ChartThemeBrownSand
            antialiasing: true
            anchors.top: parent.verticalCenter
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.right: parent.horizontalCenter

            PieSeries {
                id: miehetjanaiset
                PieSlice { label: "Suomi"; value: 84.9 }
                PieSlice { label: "Ruotsi"; value: 5.1 }
                PieSlice { label: "Venäjä"; value: 10.0 }
            }
        }
        ChartView {
            title: "Parhaat ajat eri vuosille matkalla x"
            anchors.top: parent.verticalCenter
            anchors.left: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            width: 625
            height: 325
            legend.alignment: Qt.AlignBottom
            antialiasing: true

            BarSeries {
                id: mySeries
                axisX: BarCategoryAxis { categories: ["2007", "2008", "2009", "2010", "2011", "2012" ] }
                BarSet { label: "Miehet"; values: [2, 2, 3, 4, 5, 6] ; color: "blue"}
                BarSet { label: "Naiset"; values: [5, 1, 2, 4, 1, 7] ; color: "red"}
            }
        }
    }

}
