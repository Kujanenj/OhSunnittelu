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
            width: 625
            height: 325
            id: linechart

            LineSeries {
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
            width: 625
            height: 325
            theme: ChartView.ChartThemeBlueIcy
            antialiasing: true
            anchors.left: linechart.right

            PieSeries {
                id: osallistujat
                PieSlice { label: "P50"; value: 24.9 }
                PieSlice { label: "P30"; value: 5.1 }
                PieSlice { label: "V50"; value: 70.0 }
            }
        }
        ChartView {
            title: "Miesten ja naisen osallistujamäärän suhde"
            width: 625
            height: 325
            theme: ChartView.ChartThemeBrownSand
            antialiasing: true
            anchors.top: linechart.bottom

            PieSeries {
                id: miehetjanaiset
                PieSlice { label: "Miehet"; value: 94.9 }
                PieSlice { label: "Naiset"; value: 5.1 }
            }
        }
        ChartView {
            title: "Parhaat ajat eri vuosille matkalla x"
            anchors.top: linechart.bottom
            anchors.left: linechart.right
            width: 625
            height: 325
            antialiasing: true

            LineSeries {
                name: "Naiset"
                color: "Red"
                XYPoint { x: 0; y: 0 }
                XYPoint { x: 1.1; y: 3.1 }
                XYPoint { x: 1.9; y: 4.3 }
                XYPoint { x: 2.1; y: 3.1 }
                XYPoint { x: 2.9; y: 5.9 }
                XYPoint { x: 3.4; y: 4.0 }
                XYPoint { x: 4.1; y: 4.3 }
            }
            LineSeries {
                name: "Miehet"
                color: "Blue"
                XYPoint { x: 0; y: 0 }
                XYPoint { x: 1.1; y: 2.1 }
                XYPoint { x: 1.9; y: 3.3 }
                XYPoint { x: 2.1; y: 2.1 }
                XYPoint { x: 2.9; y: 4.9 }
                XYPoint { x: 3.4; y: 3.0 }
                XYPoint { x: 4.1; y: 3.3 }
            }
        }
    }

}
