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
                    min: -0.5
                    max: 5.5

                    CategoryRange {
                        label: "Äijä"
                        endValue: 0
                        }
                    CategoryRange {
                        label: "Matti"
                        endValue: 1.5
                        }
                    CategoryRange {
                        label: "Erkki"
                        endValue: 2.5
                        }
                    CategoryRange {
                        label: "Jussi"
                        endValue: 3.5
                        }
                    CategoryRange {
                        label: "Mastiff"
                        endValue: 4.5
                        }
                    CategoryRange {
                        label: "Joku"
                        endValue: 5.5
                    }

                }
                axisY: CategoryAxis{
                    min: 1
                    max: 7

                    CategoryRange{
                        label: "2:00:00"
                        endValue: 2.5
                    }
                    CategoryRange{
                        label: "3:00:00"
                        endValue: 3.5
                    }
                    CategoryRange{
                        label: "4:00:00"
                        endValue: 4.5
                    }
                    CategoryRange{
                        label: "5:00:00"
                        endValue: 5.5
                    }
                    CategoryRange{
                        label: "6:00:00"
                        endValue: 6.5
                    }
                }

                XYPoint { x: 0; y: 2.03}
                XYPoint { x: 1; y: 2.3 }
                XYPoint { x: 2; y: 2.5 }
                XYPoint { x: 3; y: 3.4 }
                XYPoint { x: 4; y: 5.1 }
                XYPoint { x: 5; y: 6.0 }

            }
        }
    }

}
