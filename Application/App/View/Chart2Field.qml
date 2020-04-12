import QtQuick 2.0
import QtQuick.Controls 2.13
import QtCharts 2.3
import QtQuick.Window 2.12

Item {
    Frame {
        id: frame
        anchors.fill: parent
        ChartView {
            title: "Top 5 hiihtäjät keskinopeus"

            anchors.left: parent.left
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: parent.verticalCenter
            width: 625
            height: 325
            legend.alignment: Qt.AlignBottom
            antialiasing: true

            ComboBox {
                id: comboBoxSortOption
                scale: 1
                editable: false
                textRole: "text"

                onActivated:  {
                    var keskinopeus_top_5 = DataController.getGraphValues("top_5", "2015", "P50")
                    while(keskinopeudet.at(0)){
                        keskinopeudet.remove(0)
                        console.log("!!")
                    }
                    for(var i = 0; i < keskinopeus_top_5.length; i++){
                        keskinopeudet.append(keskinopeus_top_5[i] / 10)
                        console.log(keskinopeus_top_5[i])
                    }
                }

                model: ListModel {
                    id: sortOptions
                    ListElement {text: "P50"; value: "P50";}
                    ListElement {text: "V50"; value: "V50";}
                    ListElement {text: "P100"; value: "P100";}
                    ListElement {text: "P32"; value: "P32";}
                    ListElement {text: "V20"; value: "V20";}
                    ListElement {text: "V32"; value: "V32";}
                    ListElement {text: "V20jun"; value: "V20jun";}
                    ListElement {text: "P42"; value: "P42";}
                    ListElement {text: "P20"; value: "P20";}
                    ListElement {text: "P30"; value: "P30";}
                    ListElement {text: "P44"; value: "P44";}
                    ListElement {text: "P60"; value: "P60";}
                    ListElement {text: "P62"; value: "P62";}
                    ListElement {text: "P25"; value: "P25";}
                    ListElement {text: "P32"; value: "P32";}
                    ListElement {text: "P35"; value: "P35";}
                    ListElement {text: "P45"; value: "P45";}
                    ListElement {text: "P52"; value: "P52";}
                    ListElement {text: "P53"; value: "P53";}
                    ListElement {text: "P75"; value: "P75";}
                    ListElement {text: "V30"; value: "V30";}
                    ListElement {text: "V45"; value: "V45";}
                    ListElement {text: "V53"; value: "V53";}
                    ListElement {text: "V75"; value: "V75";}
                }
            }

            BarSeries {
                id: keskinopeus
                axisX: BarCategoryAxis {
                    categories: ["P100", "P20", "P32", "P42", "P50", "V100", "V20", "V20jun", "V42", "V50"  ] }

                BarSet { id: keskinopeudet; label: "Keskinopeus"; values: [21.24, 25] ; color: "blue"}
            }
        }
    }

}