import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12

import QtQuick.Controls 2.14

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

        RowLayout {
            id: rowLayout
            x: 0
            y: -6
            width: 1256
            height: 43

            Button {
                id: sortButton
                text: qsTr("Lajittele")
                scale: 0.95
                onClicked: {

                    DataController.sortButtonClicked(selected.text);
                    // Tee datacontrollerii funktio mitä haluut tehä
                    // kun lajittele buttonia painetaan
                    // selected.text välittää sulle tekstin mitä sortataan
                    // Esim. "Vuosi"
                    // DataController.sortButtonClicked(selected.text);

                }
            }

            Text {
                id: selected
                text: ""
                visible: false
            }

            RadioButton {
                id: yearRadioButton
                text: qsTr("Vuosi")
                checked: {
                    true
                    selected.text = "year"
                }
                onClicked: {
                    parent: selected.text = "year"
                }
            }

            RadioButton {
                id: distanceRadioButton
                text: qsTr("Matka")
                onClicked: {
                    parent: selected.text = "distance"
                }
            }

            RadioButton {
                id: timeRadioButton
                text: qsTr("Aika")
                onClicked: {
                    parent: selected.text = "time"
                }
            }

            RadioButton {
                id: placeRadioButton
                text: qsTr("Sija")
                onClicked: {
                    parent: selected.text = "place"
                }
            }

            RadioButton {
                id: placeMRadioButton
                text: qsTr("Sija / M")
                onClicked: {
                    parent: selected.text = "placem"
                }
            }

            RadioButton {
                id: placeNRadioButton
                text: qsTr("Sija / N")
                onClicked: {
                    parent: selected.text = "placen"
                }
            }

            RadioButton {
                id: genderRadioButton
                text: qsTr("Sukupuoli")
                onClicked: {
                    parent: selected.text = "gender"
                }
            }

            RadioButton {
                id: sfnameRadioButton
                text: qsTr("Suku- ja etunimi")
                onClicked: {
                    parent: selected.text = "sfname"
                }
            }

            RadioButton {
                id: cityRadioButton
                text: qsTr("Paikkakunta")
                onClicked: {
                    parent: selected.text = "city"
                }
            }

            RadioButton {
                id: nationalityRadioButton
                text: qsTr("Kansallisuus")
                onClicked: {
                    parent: selected.text = "nationality"
                }
            }

            RadioButton {
                id: ageRadioButton
                text: qsTr("Syntymävuosi")
                onClicked: {
                    parent: selected.text = "age"
                }
            }

            RadioButton {
                id: teamRadioButton
                text: qsTr("Joukkue")
                onClicked: {
                    parent: selected.text = "team"
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
    D{i:0;autoSize:true;height:720;width:1280}
}
##^##*/
