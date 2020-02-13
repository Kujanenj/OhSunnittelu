import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.14
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.14
import QtCharts 2.14

ApplicationWindow {
    TabBar {
        id: bar
        width: parent.width
        currentIndex: 0

        TabButton {
            text: qsTr("Haku")
            checked: true
        }
        TabButton {
            text: qsTr("Tulokset")
            checked: false
        }

        TabButton {
            text: qsTr("Kaaviot")
            checked: false
        }
        TabButton {
            text: qsTr("Extra")
            checked: false
        }
    }

    StackLayout {
        x: 513
        y: 64
        width: parent.width
        currentIndex: bar.currentIndex
        Item {
            id: searchTab

            Frame {
                id: frame
                x: -513
                y: -18
                width: 501
                height: 777

                InputFields {
                    anchors.leftMargin: 0
                    anchors.topMargin: 0
                    anchors.rightMargin: 40
                    anchors.bottomMargin: 191
                    anchors.fill: parent
                }
            }
        }
        Item {
            id: filterTab
        }
        Item {
            id: graphTab
        }
    }

    id: applicationWindow
    width: 640
    height: 640
    visible: true
    title: qsTr("Finlandia Skiing Database")

    // Input fields for user to do a search
}


