import QtQuick 2.0
import QtQuick.Controls 2.13
import QtCharts 2.3
import QtQuick.Window 2.12

Item {
    Frame {
        id: frame
        anchors.fill: parent

        ChartView {
            title: "Aikataulukko"
            anchors.fill: parent
            antialiasing: true

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
    }

}
