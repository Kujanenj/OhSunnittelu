import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12
import QtQuick.Controls 2.10

Item {
    Frame {
        id: frame1
        x: 0
        y: 43
        anchors.topMargin: 0
        anchors.fill: parent

        TableView {
            id: tableView
            x: -12
            y: -54
            anchors.topMargin: 43
            anchors.fill: parent

            TableViewColumn {
                role: "year"
                title: "Year"
                width: 100
            }
            TableViewColumn {
                role: "distance"
                title: "Distance"
                width: 100
            }
            TableViewColumn {
                role: "time"
                title: "Time"
                width: 100
            }
            TableViewColumn {
                role: "place"
                title: "Rank"
                width: 100
            }
            TableViewColumn {
                role: "placem"
                title: "Rank | M"
                width: 100
            }
            TableViewColumn {
                role: "placen"
                title: "Rank | W"
                width: 100
            }
            TableViewColumn {
                role: "gender"
                title: "Gender"
                width: 100
            }
            TableViewColumn {
                role: "sfname"
                title: "Name"
                width: 100
            }
            TableViewColumn {
                role: "city"
                title: "City"
                width: 100
            }
            TableViewColumn {
                role: "nationality"
                title: "Nationality"
                width: 100
            }
            TableViewColumn {
                role: "age"
                title: "Age"
                width: 100
            }
            TableViewColumn {
                role: "team"
                title: "Team"
                width: 100
            }

            model: resultModel

            rowDelegate: Rectangle {
                anchors.fill: parent
                color: styleData.selected ? 'skyblue' : (styleData.alternate ? 'whitesmoke' : 'white');
                MouseArea {
                    anchors.fill: parent
                    acceptedButtons: Qt.RightButton | Qt.LeftButton
                    onClicked: {
                        tableView.selection.clear()
                        tableView.selection.select(styleData.row)
                        tableView.currentRow = styleData.row
                        tableView.focus = true

                        switch(mouse.button) {
                        case Qt.RightButton:
                            contextMenu.popup()
                            break
                        default:
                            break
                        }
                    }
                }
            }
        }

        RowLayout {
            id: rowLayout
            x: 0
            y: -6
            width: 1256
            height: 48

            /*
            Text {
                id: selected
                text: ""
                visible: false
            }
            */

            ComboBox {
                id: comboBoxSortOption
                Layout.fillWidth: true
                Layout.topMargin: 0
                Layout.fillHeight: false
                scale: 1
                editable: false
                textRole: "text"

                onActivated:  {
                    DataController.sortButtonClicked(sortOptions.get(comboBoxSortOption.currentIndex).value,rangeSliderTime.first.value,rangeSliderTime.second.value, rankSlider.value);

                    console.log(sortOptions.get(comboBoxSortOption.currentIndex).value + " syötetty datacontrollerille parametrina")
                }

                model: ListModel {
                    id: sortOptions
                    ListElement {text: "Year"; value: "year"}
                    ListElement {text: "Distance"; value: "distance"}
                    ListElement {text: "Time"; value: "time"}
                    ListElement {text: "Rank"; value: "place"}
                    ListElement {text: "Rank | M"; value: "placem"}
                    ListElement {text: "Rank | W"; value: "placen"}
                    ListElement {text:"Gender"; value:"gender"}
                    ListElement {text:"Name"; value:"sfname"}
                    ListElement {text:"City"; value:"city"}
                    ListElement {text:"Nationality"; value:"nationality"}
                    ListElement {text:"Age"; value:"age"}
                    ListElement {text:"Team"; value:"team"}
                }
            }

            //TIME AND AGE FILTER SLIDERS DOWN:
            RangeSlider {
                id: rangeSliderTime
                enabled: true
                Layout.fillWidth: true
                from: 1
                to: 9
                stepSize: 1.0
                first.value: 1
                second.value: 9
                snapMode: "SnapAlways"

                first.onPressedChanged: {
                    if(!first.pressed) {
                       DataController.sortButtonClicked(sortOptions.get(comboBoxSortOption.currentIndex).value,rangeSliderTime.first.value,rangeSliderTime.second.value, rankSlider.value);
                    }
                }

                second.onPressedChanged: {
                    if(!second.pressed) {
                       DataController.sortButtonClicked(sortOptions.get(comboBoxSortOption.currentIndex).value,rangeSliderTime.first.value,rangeSliderTime.second.value, rankSlider.value);
                        // Eli ajan alarajan saat rangeSliderTime.first.value
                        // ja ajan ylärajan saat rangeSliderTime.second.value
                        // Eli noi kaks parametrii ja DataControlleriin funktiokutsu
                    }
                }

                Text {
                    id: hiText
                    x: 386
                    y: -5
                    text: parent.second.value + " hour(s)"
                    anchors.rightMargin: 6
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 35
                    anchors.right: parent.right
                }

                Text {
                    id: lowText
                    x: -820
                    y: -5
                    text: parent.first.value + " hour(s)"
                    anchors.bottom: parent.bottom
                    anchors.bottomMargin: 35
                    anchors.leftMargin: 8
                    anchors.left: parent.left
                }

                Text {
                    id: textTimeRangeInfo
                    x: -73
                    y: 13
                    width: 0
                    height: 14
                    text: qsTr("Time range: ")
                    anchors.verticalCenterOffset: -21
                    anchors.horizontalCenterOffset: 0
                    anchors.verticalCenter: parent.verticalCenter
                    anchors.horizontalCenter: parent.horizontalCenter
                    font.pixelSize: 12
                }
            }
            /*
            CheckBox {
                id: checkBoxTimeRange
                x: 182
                y: 12
                width: 55
                height: 40
                scale: 0.5

                onClicked: {
                    if(rangeSliderTime.enabled === false)
                        rangeSliderTime.enabled = true
                    else{
                        rangeSliderTime.enabled = false
                        rangeSliderTime.first.value = 1
                        rangeSliderTime.second.value = 12
                    }
                }
            }
            */

            Slider {
                enabled: true
                id: rankSlider
                value: 1500
                stepSize: 10
                to: 1500
                from: 10

                onPressedChanged: {
                    if(!pressed) {
                       DataController.sortButtonClicked(sortOptions.get(comboBoxSortOption.currentIndex).value,rangeSliderTime.first.value,rangeSliderTime.second.value, rankSlider.value);
                    }
                }

                Text {
                    id: rankTextInfo
                    x: 30
                    y: -4
                    width: 99
                    height: 14
                    text: qsTr("Rank range: ")
                    anchors.right: parent.right
                    anchors.rightMargin: 71
                    anchors.verticalCenterOffset: -20
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 12
                }
                Text {
                    id: rankTextValue
                    x: -820
                    y: -5
                    text: "Top " + rankSlider.value
                    anchors.verticalCenterOffset: -20
                    anchors.horizontalCenterOffset: 70
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                }
            }
            /*
            CheckBox {
                id: checkBoxRankRange
                x: -4
                y: -20
                width: 47
                height: 40
                scale: 0.5

                onClicked: {
                    if(rankSlider.enabled === false)
                        rankSlider.enabled = true
                    else{
                        rankSlider.enabled = false
                        rankSlider.value = 1500
                    }
                }
            }
            */
        }
    }

    Menu {
        id: contextMenu

        MenuItem {
            text: qsTr("Show all personal results")
            onTriggered: {
                var anArray = resultModel.getData(tableView.currentRow)
                var distances = ["kaikki"]
                var ages = ["kaikki"]
                var personalSearch = "Personal"
                console.log(anArray[0], anArray[1], anArray[2])
                DataController.searchButtonClicked("1974", "2019", distances, "kaikki", ages, anArray[1], anArray[0], anArray[2], "0", "", personalSearch)
                personalResultModel.updateModel("PersonalResults")
                bar.currentIndex = 2
                chartButton1.enabled = false
                chartButton2.enabled = false
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:720;width:1280}D{i:36;anchors_x:"-67";anchors_y:13}D{i:37;anchors_x:182;anchors_y:12}
D{i:39;anchors_x:"-820";anchors_y:"-5"}D{i:38;anchors_height:14;anchors_width:99;anchors_x:35;anchors_y:"-4"}
D{i:17;anchors_height:43;anchors_width:1256;anchors_x:0;anchors_y:"-6"}
}
##^##*/
