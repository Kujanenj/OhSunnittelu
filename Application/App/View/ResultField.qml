import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12

import QtQuick.Controls 2.10

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
                title: "Year"
                width: 100
            }
            TableViewColumn {
                role: "distance"
                title: "Distance"
                width: 100
            }
            TableViewColumn {
                role: "time"
                title: "Time"
                width: 100
            }
            TableViewColumn {
                role: "place"
                title: "Rank"
                width: 100
            }
            TableViewColumn {
                role: "placem"
                title: "Rank | M"
                width: 100
            }
            TableViewColumn {
                role: "placen"
                title: "Rank | W"
                width: 100
            }
            TableViewColumn {
                role: "gender"
                title: "Gender"
                width: 100
            }
            TableViewColumn {
                role: "sfname"
                title: "Name"
                width: 100
            }
            TableViewColumn {
                role: "city"
                title: "City"
                width: 100
            }
            TableViewColumn {
                role: "nationality"
                title: "Nationality"
                width: 100
            }
            TableViewColumn {
                role: "age"
                title: "Age"
                width: 100
            }
            TableViewColumn {
                role: "team"
                title: "Team"
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
                text: qsTr("Sort")
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
                text: qsTr("Year")
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
                text: qsTr("Distance")
                onClicked: {
                    parent: selected.text = "distance"
                }
            }

            RadioButton {
                id: timeRadioButton
                text: qsTr("Time")
                onClicked: {
                    parent: selected.text = "time"
                }
            }

            RadioButton {
                id: placeRadioButton
                text: qsTr("Rank")
                onClicked: {
                    parent: selected.text = "place"
                }
            }

            RadioButton {
                id: placeMRadioButton
                text: qsTr("Rank | M")
                onClicked: {
                    parent: selected.text = "placem"
                }
            }

            RadioButton {
                id: placeNRadioButton
                text: qsTr("Rank | W")
                onClicked: {
                    parent: selected.text = "placen"
                }
            }

            RadioButton {
                id: genderRadioButton
                text: qsTr("Gender")
                onClicked: {
                    parent: selected.text = "gender"
                }
            }

            RadioButton {
                id: sfnameRadioButton
                text: qsTr("Name")
                onClicked: {
                    parent: selected.text = "sfname"
                }
            }

            RadioButton {
                id: cityRadioButton
                text: qsTr("City")
                onClicked: {
                    parent: selected.text = "city"
                }
            }

            RadioButton {
                id: nationalityRadioButton
                text: qsTr("Nationality")
                onClicked: {
                    parent: selected.text = "nationality"
                }
            }

            RadioButton {
                id: ageRadioButton
                text: qsTr("Age")
                onClicked: {
                    parent: selected.text = "age"
                }
            }

            RadioButton {
                id: teamRadioButton
                text: qsTr("Team")
                onClicked: {
                    parent: selected.text = "team"
                }
            }
        }

    }

    Menu {
        id: contextMenu

        MenuItem {
            text: qsTr("More info")
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
