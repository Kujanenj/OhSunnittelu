import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.12

import QtQuick.Controls 2.14

Item {

    RowLayout {
        id: rowLayout
        anchors.fill: parent

        Row {
            id: row
            width: 200
            height: 400
            Layout.fillHeight: true
            Layout.fillWidth: true

            Frame {
                id: frame
                anchors.fill: parent
                Layout.fillHeight: true
                Layout.fillWidth: true

                TableView {
                    id: tableView
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
                        title: "Vuosi"
                        role: "year"
                    }

                    TableViewColumn {
                        width: 80
                        title: "Matka"
                        role: "distance"
                    }

                    TableViewColumn {
                        width: 80
                        title: "Aika"
                        role: "time"
                    }

                    TableViewColumn {
                        width: 80
                        title: "Sija"
                        role: "place"
                    }

                    TableViewColumn {
                        width: 80
                        title: "Sija/miehet"
                        role: "placem"
                    }

                    TableViewColumn {
                        width: 80
                        title: "Sija/naiset"
                        role: "placen"
                    }

                    TableViewColumn {
                        width: 80
                        title: "Sukupuoli"
                        role: "gender"
                    }

                    TableViewColumn {
                        width: 80
                        title: "Suku- ja etunimi"
                        role: "sfname"
                    }

                    TableViewColumn {
                        width: 80
                        title: "Paikkakunta"
                        role: "city"
                    }

                    TableViewColumn {
                        width: 80
                        title: "Kansallisuus"
                        role: "nationality"
                    }

                    TableViewColumn {
                        width: 80
                        title: "Syntymävuosi"
                        role: "age"
                    }

                    TableViewColumn {
                        width: 80
                        title: "Joukkue"
                        role: "team"
                    }
                }
            }
        }

        Row {
            id: row1
            width: 200
            height: 400
            Layout.fillHeight: true
            Layout.fillWidth: true

            Frame {
                id: frame1
                anchors.fill: parent
                Layout.fillHeight: true
                Layout.fillWidth: false

                ColumnLayout {
                    id: columnLayout
                    anchors.fill: parent

                    RowLayout {
                        id: rowLayout1
                        width: 100
                        height: 100

                        Text {
                            id: element
                            text: qsTr("Urheilijan nimi:")
                            font.pixelSize: 20
                        }

                        Text {
                            id: element1
                            text: qsTr("Jussi Kujanen")
                            font.pixelSize: 20
                        }
                    }

                    RowLayout {
                        id: rowLayout2
                        width: 100
                        height: 100
                        Text {
                            id: element2
                            text: qsTr("TOP 10 - Sijoituksia")
                            font.pixelSize: 20
                        }

                        Text {
                            id: element3
                            text: qsTr("5 kpl")
                            font.pixelSize: 20
                        }
                    }

                    RowLayout {
                        id: rowLayout3
                        width: 100
                        height: 100
                        Text {
                            id: element4
                            text: qsTr("Kaikki osallistumiskerrat:")
                            font.pixelSize: 20
                        }

                        Text {
                            id: element5
                            text: qsTr("10 osallistumista")
                            font.pixelSize: 20
                        }
                    }

                    RowLayout {
                        id: rowLayout4
                        width: 100
                        height: 100
                        Text {
                            id: element6
                            text: qsTr("Osallistumisvuodet")
                            font.pixelSize: 20
                        }

                        Text {
                            id: element7
                            text: qsTr("1998, 2008, 2016, 2019")
                            font.pixelSize: 20
                        }
                    }

                    RowLayout {
                        id: rowLayout5
                        width: 100
                        height: 100
                        Text {
                            id: element8
                            text: qsTr("Lista eri hiihtomatkoista:")
                            font.pixelSize: 20
                        }

                        Text {
                            id: element9
                            text: qsTr("P50, V50")
                            font.pixelSize: 20
                        }
                    }

                    RowLayout {
                        id: rowLayout6
                        width: 100
                        height: 100
                        Text {
                            id: element10
                            text: qsTr("Paras aika: ")
                            font.pixelSize: 20
                        }

                        Text {
                            id: element11
                            text: qsTr("3:25:56")
                            font.pixelSize: 20
                        }
                    }
                }
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:720;width:1280}D{i:3;anchors_height:200;anchors_width:200}
D{i:20;anchors_height:200;anchors_width:200}
}
##^##*/
