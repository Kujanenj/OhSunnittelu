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
        width: 360
        anchors.left: parent.left
    }

    background: BorderImage {
        id: backgroundImage
        source: "images/riku.jpg"
        anchors.fill: parent
        border.left: 5; border.top: 5
        border.right: 5; border.bottom: 5
    }


    // Input fields for user to do a search
    InputFields {
        anchors.leftMargin: 7
        anchors.topMargin: 16
        anchors.bottomMargin: 114
        anchors.right: parent.right
        anchors.rightMargin: 26
        anchors.bottom: parent.bottom
        anchors.left: parent.left
        anchors.top: parent.top
    }

}

/*##^##
Designer {
    D{i:3;anchors_height:500;anchors_width:640}
}
##^##*/
