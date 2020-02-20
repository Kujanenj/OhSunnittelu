import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    TableView {
        id: tableView
        anchors.fill: parent
        TableViewColumn {
            role: "year"
            title: "Vuosi"
            width: 100
        }
        TableViewColumn {
            role: "distance"
            title: "Matka"
            width: 100
        }
        TableViewColumn {
            role: "time"
            title: "Aika"
            width: 100
        }
        TableViewColumn {
            role: "place"
            title: "Sija"
            width: 100
        }
        TableViewColumn {
            role: "placem"
            title: "Sija/miehet"
            width: 100
        }
        TableViewColumn {
            role: "placen"
            title: "Sija/naiset"
            width: 100
        }
        TableViewColumn {
            role: "gender"
            title: "Sukupuoli"
            width: 100
        }
        TableViewColumn {
            role: "sfname"
            title: "Suku- ja etunimi"
            width: 100
        }
        TableViewColumn {
            role: "city"
            title: "Paikkakunta"
            width: 100
        }
        TableViewColumn {
            role: "nationality"
            title: "Kansallisuus"
            width: 100
        }
        TableViewColumn {
            role: "age"
            title: "Syntymävuosi"
            width: 100
        }
        TableViewColumn {
            role: "team"
            title: "Joukkue"
            width: 100
        }

        model: myModel

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

    Menu {
        id: contextMenu

        MenuItem {
            text: qsTr("Lisätietoa")
            onTriggered: {
                bar.currentIndex = 2
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
