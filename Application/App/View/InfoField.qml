import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12

import QtQuick.Controls 2.14

Item {

    RowLayout {
        id: rowLayout7
        anchors.fill: parent

        Frame {
            id: frame2
            width: 200
            height: 200
            Layout.fillHeight: true
            Layout.fillWidth: true

            TableView {
                id: tableView
                anchors.fill: parent
                rowDelegate: Rectangle {
                    color: styleData.selected ? 'skyblue' : (styleData.alternate ? 'whitesmoke' : 'white')
                    MouseArea {
                        anchors.fill: parent
                        acceptedButtons: Qt.RightButton | Qt.LeftButton
                    }
                    anchors.fill: parent
                }
                TableViewColumn {
                    width: 80
                    title: "Year"
                    role: "year"
                }

                TableViewColumn {
                    width: 80
                    title: "Distance"
                    role: "distance"
                }

                TableViewColumn {
                    width: 80
                    title: "Time"
                    role: "time"
                }

                TableViewColumn {
                    width: 80
                    title: "Rank"
                    role: "place"
                }

                TableViewColumn {
                    width: 80
                    title: "Rank | M"
                    role: "placem"
                }

                TableViewColumn {
                    width: 80
                    title: "Rank | W"
                    role: "placen"
                }

                TableViewColumn {
                    width: 80
                    title: "Gender"
                    role: "gender"
                }

                TableViewColumn {
                    width: 80
                    title: "Name"
                    role: "sfname"
                }

                TableViewColumn {
                    width: 80
                    title: "City"
                    role: "city"
                }

                TableViewColumn {
                    width: 80
                    title: "Nationality"
                    role: "nationality"
                }

                TableViewColumn {
                    width: 80
                    title: "Age"
                    role: "age"
                }

                TableViewColumn {
                    width: 80
                    title: "Team"
                    role: "team"
                }
            }
        }

        Frame {
            id: frame1
            Layout.fillHeight: true
            Layout.fillWidth: false

            ColumnLayout {
                id: columnLayout
                anchors.fill: parent

                RowLayout {
                    id: rowLayout1
                    width: 100
                    height: 100
                    Layout.fillHeight: false
                    Layout.fillWidth: false

                    Text {
                        id: element
                        text: qsTr("Athlete's name: ")
                        font.pixelSize: 20
                    }

                    Text {
                        id: element1
                        text: qsTr("Jussi Kujanen")
                        font.pixelSize: 20
                    }
                }

                RowLayout {
                    id: rowLayout2
                    width: 100
                    height: 100
                    Text {
                        id: element2
                        text: qsTr("TOP 10 - Records: ")
                        font.pixelSize: 20
                    }

                    Text {
                        id: element3
                        text: qsTr("5")
                        font.pixelSize: 20
                    }
                }

                RowLayout {
                    id: rowLayout3
                    width: 100
                    height: 100
                    Text {
                        id: element4
                        text: qsTr("Participation times: ")
                        font.pixelSize: 20
                    }

                    Text {
                        id: element5
                        text: qsTr("10")
                        font.pixelSize: 20
                    }
                }

                RowLayout {
                    id: rowLayout4
                    width: 100
                    height: 100
                    Text {
                        id: element6
                        text: qsTr("Participation years: ")
                        font.pixelSize: 20
                    }

                    Text {
                        id: element7
                        text: qsTr("1998, 2008, 2016, 2019")
                        font.pixelSize: 20
                    }
                }

                RowLayout {
                    id: rowLayout5
                    width: 100
                    height: 100
                    Text {
                        id: element8
                        text: qsTr("Participation skiing types: ")
                        font.pixelSize: 20
                    }

                    Text {
                        id: element9
                        text: qsTr("P50, V50")
                        font.pixelSize: 20
                    }
                }

                RowLayout {
                    id: rowLayout6
                    width: 100
                    height: 100
                    Text {
                        id: element10
                        text: qsTr("Best time: ")
                        font.pixelSize: 20
                    }

                    Text {
                        id: element11
                        text: qsTr("3:25:56")
                        font.pixelSize: 20
                    }
                }
            }
        }
    }

}

/*##^##
Designer {
    D{i:0;autoSize:true;height:720;width:1280}D{i:1;anchors_height:100;anchors_width:100}
}
##^##*/
