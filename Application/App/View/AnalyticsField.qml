import QtQuick 2.0
import QtQuick.Controls 2.13
import QtQuick.Window 2.12
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12

/**
  * represents analytics tab contents in the UI
 */

Item {


    Frame {
        id: frame1
        anchors.rightMargin: 0
        anchors.fill: parent
    }


    ColumnLayout {
        id: columnLayout
        anchors.bottomMargin: 5
        anchors.topMargin: 5
        anchors.leftMargin: 8
        anchors.rightMargin: 8
        anchors.fill: parent

        Text {
            id: element1
            x: 15
            y: 3
            text: qsTr("Analytics from results:")
            Layout.rowSpan: 1
            Layout.fillHeight: false
            Layout.fillWidth: false
            font.pixelSize: 14
        }

        TableView {
            id: tableView
            Layout.fillHeight: true
            Layout.fillWidth: true
            scale: 1
            activeFocusOnTab: true
            alternatingRowColors: true
            backgroundVisible: true
            flickableItem.pixelAligned: false
            frameVisible: true
            headerVisible: true

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
                title: "Average time"
                role: "avgtime"
            }

            TableViewColumn {
                width: 80
                title: "Participants"
                role: "participants"
            }

            TableViewColumn {
                width: 90
                title: "Fastest time"
                role: "fastesttime"
            }

            TableViewColumn {
                width: 90
                title: "Slowest time"
                role: "slowesttime"
            }

            TableViewColumn {
                width: 120
                title: "1st place"
                role: "winner"
            }

            TableViewColumn {
                width: 120
                title: "2nd place"
                role: "second"
            }

            TableViewColumn {
                width: 120
                title: "3rd place"
                role: "third"
            }

            TableViewColumn {
                width: 115
                title: "Average speed (km/h)"
                role: "averagespeed"
            }

            TableViewColumn {
                width: 160
                title: "Winner's average speed (km/h)"
                role: "winnerspeed"
            }

            TableViewColumn {
                width: 125
                title: "Best team"
                role: "bestteam"
            }

            model: analyticsModel
        }

        Text {
            id: element
            x: 15
            text: qsTr("Personal results:")
            Layout.fillHeight: false
            Layout.fillWidth: false
            font.pixelSize: 14
        }

        TableView {
            id: tableView1
            Layout.fillHeight: true
            Layout.fillWidth: true
            model: personalResultModel
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
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:200;anchors_width:200}
D{i:2;anchors_height:100;anchors_width:100}
}
##^##*/
