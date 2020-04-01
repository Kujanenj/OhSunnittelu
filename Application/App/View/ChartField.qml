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
            title: "Matkan parhaiden hiihtäjien ero voittajaan"
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
                    
                    var ajat_values = DataController.getGraphValues("ajat", "2019", "P50");
                    
                    series.clear();
                    var eka = ajat_values[0]
                    for(var i = 0; i < ajat_values.length; i++){
                        series.append(i+0.5, (ajat_values[i]-eka)/100)
                    }
                    var kansallisuudet_values = DataController.getGraphValues("kansallisuudet", "2019", "P50");
                    var kansallisuudet = DataController.getGraphTypes("kansallisuudet", "2019", "P50")
                    maat.clear()
                    for(i = 0; i < kansallisuudet_values.length; i++){
                        maat.append(kansallisuudet[i], kansallisuudet_values[i])
                    }

                    var osallistujat_values = DataController.getGraphValues("osallistujat", "2019", "P50")
                    var osallistuja = DataController.getGraphTypes("osallistujat", "2019", "P50")
                    osallistujat.clear()

                    for(i = 0; i < osallistujat_values.length; i++){
                        osallistujat.append(osallistuja[i], osallistujat_values[i])
                    }

                    /**
                    var matkan_parhaat_m_values = DataController.getGraphValues("parhaat_m", "2019", "P50")
                    var matkan_parhaat_n_values = DataController.getGraphValues("parhaat_n", "2019", "P50")
                    parhaat.clear()
                    console.log(matkan_parhaat_m_values)
                    parhaat.append("Miehet", matkan_parhaat_m_values )
                    **/


                }

            }

            LineSeries {
                id: series
                name: "Ajat"

                axisX: CategoryAxis{
                    min: 0
                    max: 10

                    CategoryRange {
                        label: "1"
                        endValue: 1
                        }
                    CategoryRange {
                        label: "2"
                        endValue: 2
                        }
                    CategoryRange {
                        label: "3"
                        endValue: 3
                        }
                    CategoryRange {
                        label: "4"
                        endValue: 4
                        }
                    CategoryRange {
                        label: "5"
                        endValue: 5
                        }
                    CategoryRange {
                        label: "6"
                        endValue: 6
                    }
                    CategoryRange {
                        label: "7"
                        endValue: 7
                    }
                    CategoryRange {
                        label: "8"
                        endValue: 8
                    }
                    CategoryRange {
                        label: "9"
                        endValue: 9
                    }
                    CategoryRange {
                        label: "10"
                        endValue: 10
                    }

                }
                axisY: CategoryAxis{
                    min: 0
                    max: 1

                    CategoryRange{
                        label: "0:12:00"
                        endValue: .2
                    }

                    CategoryRange{
                        label: "0:24:00"
                        endValue: .4
                    }

                    CategoryRange{
                        label: "0:36:00"
                        endValue: .6
                    }
                    CategoryRange{
                        label: "0:48:00"
                        endValue: .8
                    }
                    CategoryRange{
                        label: "1:00:00"
                        endValue: 1
                    }
                }

                XYPoint { x: 0.5; y: 2.0 }
                XYPoint { x: 1.5; y: 2.3 }
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
            anchors.top: parent.verticalCenter
            anchors.left: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.right: parent.right

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
                id: maat
                PieSlice { label: "Suomi"; value: 84.9 }
                PieSlice { label: "Ruotsi"; value: 5.1 }
                PieSlice { label: "Venäjä"; value: 10.0 }
            }
        }
        ChartView {
            title: "Parhaat ajat eri vuosille matkalla x"

            anchors.left: parent.horizontalCenter
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: parent.verticalCenter
            width: 625
            height: 325
            legend.alignment: Qt.AlignBottom
            antialiasing: true

            BarSeries {
                id: parhaat
                axisX: BarCategoryAxis { id: years
                    categories: ["2010", "2011", "2012", "2013", "2014", "2015", "2016", "2017", "2018", "2019"  ] }
                axisY: BarCategoryAxis{
                    categories: ["0:00:00", "1:00:00", "2:00:00", "3:00:00", "4:00:00", "5:00:00"]
                    }
                BarSet { label: "Miehet"; values: [2, 2, 3.32, 4, 2.24, 4.12] ; color: "blue"}
                BarSet { label: "Naiset"; values: [5, 1, 2, 4, 1.12, 2] ; color: "red"}
            }
        }
    }

}
