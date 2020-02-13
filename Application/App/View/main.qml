import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    id: applicationWindow
    width: 640
    height: 640
    visible: true
    title: qsTr("Finlandia Skiing Database")

    Rectangle {
        id: rectInputBackground
        color: "whitesmoke"
        height: parent.height
        width: parent.width
        anchors.left: parent.left
    }

    // Input fields for user to do a search

    Frame {
        id: frame
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


