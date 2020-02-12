import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4

ApplicationWindow {
    visible: true
    width: screen.width/1.5
    height: screen.height/1.5
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
        source: "images/riku2.jpg"
        anchors.fill: parent
        border.left: 5; border.top: 5
        border.right: 5; border.bottom: 5
    }


    // Input fields for user to do a search
    InputFields {
    }

}
