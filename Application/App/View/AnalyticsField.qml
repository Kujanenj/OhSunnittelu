import QtQuick 2.0
import QtQuick.Controls 2.13
import QtQuick.Window 2.12

import QtQuick.Controls 1.4

Item {
    Frame {
        id: frame
        anchors.fill: parent

        TableView {
            id: tableView
            scale: 1
            activeFocusOnTab: true
            alternatingRowColors: true
            backgroundVisible: true
            flickableItem.pixelAligned: false
            frameVisible: true
            headerVisible: true
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
                title: "Distance"
                role: "distance"
            }

            TableViewColumn {
                width: 80
                title: "Average speed"
                role: "avgspeed"
            }

            TableViewColumn {
                width: 80
                title: "Participants"
                role: "participants"
            }

            TableViewColumn {
                width: 80
                title: "Fastest time"
                role: "fastesttime"
            }

            TableViewColumn {
                width: 80
                title: "Slowest time"
                role: "slowesttime"
            }

            TableViewColumn {
                width: 80
                title: "1st place"
                role: "winner"
            }

            TableViewColumn {
                width: 80
                title: "2nd place"
                role: "second"
            }

            TableViewColumn {
                width: 80
                title: "3rd place"
                role: "sfname"
            }
        }
    }
}
