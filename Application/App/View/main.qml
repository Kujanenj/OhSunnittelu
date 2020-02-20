 import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.11
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.12

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
            text: qsTr("Tarkemmat tulokset")
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
        anchors.rightMargin: 5
        anchors.leftMargin: 5
        anchors.bottomMargin: 5
        anchors.topMargin: 45
        anchors.fill: parent
        currentIndex: bar.currentIndex
        Item {
            id: searchTab

            Frame {
                id: frame
                anchors.fill: parent

                InputFields {
                    anchors.fill: parent
                }
            }
        }
        Item {
            id: resultTab

            Frame {
                id: frame1
                x: 0
                y: -2
                anchors.topMargin: 43
                anchors.fill: parent

                Table {
                    id: table
                    anchors.topMargin: 0
                    anchors.fill: parent
                    anchors.bottom: parent.bottom
                }
            }

            RowLayout {
                id: rowLayout
                x: 0
                y: 0
                width: 1270
                height: 37

                Button {
                    id: button
                    text: qsTr("Lajittele")
                    scale: 0.95
                }

                RadioButton {
                    id: radioButton
                    text: qsTr("Vuosi")
                    checked: true
                }

                RadioButton {
                    id: radioButton1
                    text: qsTr("Matka")
                }

                RadioButton {
                    id: radioButton2
                    text: qsTr("Aika")
                }

                RadioButton {
                    id: radioButton3
                    text: qsTr("Sija / M")
                }

                RadioButton {
                    id: radioButton4
                    text: qsTr("Sija / N")
                }

                RadioButton {
                    id: radioButton5
                    text: qsTr("Sukupuoli")
                }

                RadioButton {
                    id: radioButton6
                    text: qsTr("Suku- ja etunimi")
                }

                RadioButton {
                    id: radioButton7
                    text: qsTr("Paikkakunta")
                }

                RadioButton {
                    id: radioButton8
                    text: qsTr("Kansallisuus")
                }

                RadioButton {
                    id: radioButton9
                    text: qsTr("Syntymävuosi")
                }

                RadioButton {
                    id: radioButton10
                    text: qsTr("Joukkue")
                }
            }
        }
        Item {
            id: chartTab

            Frame {
                id: frame2
                x: 0
                y: -2
                anchors.fill: parent
            }
        }
        Item {
            id: extraTab

            Frame {
                id: frame3
                x: 0
                y: -2
                anchors.fill: parent
            }
        }
    }

    id: applicationWindow
    width: 1280
    height: 720
    visible: true
    title: qsTr("Finlandia Skiing Database")

    // Input fields for user to do a search
}



/*##^##
Designer {
    D{i:6;anchors_width:1280;anchors_x:513;anchors_y:64}D{i:1;anchors_width:1280}D{i:8;anchors_height:666;anchors_width:1261;anchors_x:"-502";anchors_y:"-18"}
D{i:12;anchors_x:"-12";anchors_y:"-12"}D{i:11;anchors_height:666;anchors_width:1261;anchors_x:"-502";anchors_y:"-18"}
D{i:27;anchors_height:666;anchors_width:1261;anchors_x:"-502";anchors_y:"-18"}D{i:29;anchors_height:666;anchors_width:1261;anchors_x:"-502";anchors_y:"-18"}
}
##^##*/
