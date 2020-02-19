import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    TableView {
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

        Button {
            id: button
            x: 265
            y: -1
            text: qsTr("Update")
            onClicked: {
                myModel.updateModel()
            }
        }

        Button {
            id: button1
            x: 351
            y: 0
            text: qsTr("Reset")
            onClicked: {
                database.removeData()
                myModel.updateModel()
            }
        }

        model: myModel
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
