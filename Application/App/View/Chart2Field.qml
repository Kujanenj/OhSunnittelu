import QtQuick 2.0
import QtQuick.Controls 2.13
import QtCharts 2.3
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3

Item {

    function updateDropDown() {
        var years = DataController.getYears();
        comboBoxSortYears.model = years;
    }

    function comboFunction() {
        var year = "2008"
        distances.categories = DataController.getDistances(year)
        var keskinopeus_top_5 = DataController.getGraphValues("top_5", year, "P50")
        while(keskinopeudet.at(0)){
            keskinopeudet.remove(0)
        }
        for(var i = 0; i < keskinopeus_top_5.length; i++){
            keskinopeudet.append(keskinopeus_top_5[i] / 10)
        }
    }

    Frame {
        id: frame
        anchors.topMargin: 49
        anchors.fill: parent

        ComboBox {
            id: comboBoxSortOption
            x: -12
            y: -56
            scale: 1
            editable: false
            textRole: "text"

            onActivated:  {
                comboFunction()
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

        ColumnLayout {
            id: columnLayout
            anchors.fill: parent

            ChartView {
                title: "Top 5 hiihtäjät keskinopeus"
                Layout.fillHeight: true
                Layout.fillWidth: true
                legend.alignment: Qt.AlignBottom
                antialiasing: true
                theme: ChartView.ChartThemeDark

                BarSeries {
                    id: keskinopeus
                    axisX: BarCategoryAxis { id:distances;
                        categories: ["P100", "P50" ] }

                    BarSet { id: keskinopeudet; label: "Average speed"; values: [21.24, 25] ; color: "blue"}
                }
            }

            ChartView {
                Layout.fillHeight: true
                Layout.fillWidth: true
                legend.alignment: Qt.AlignBottom
                title: "Top 10 teams"
                theme: ChartView.ChartThemeDark

                BarSeries {
                    id: top10teams
                    axisX: BarCategoryAxis {
                        id: teams
                        categories: ["Team 1", "Team 2" ]
                    }
                    BarSet {
                        id: keskinopeudet1
                        color: "#0000ff"
                        label: "Average speed"
                        values: [21.24, 25]
                    }
                }
                antialiasing: true
            }

        }

        ComboBox {
            id: comboBoxSortYears
            x: 134
            y: -56
            displayText: currentIndex === -1 ? "Years" : currentText

            onActiveFocusChanged: {
                updateDropDown()
            }

            onActivated:  {
                comboFunction()
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:7;anchors_height:325;anchors_width:625;anchors_x:6;anchors_y:1}
D{i:11;anchors_x:"-11";anchors_y:"-56"}D{i:2;anchors_height:100;anchors_width:100}
}
##^##*/
