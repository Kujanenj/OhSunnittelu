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
            role: "gender"
            title: "Sukupuoli"
            width: 100
        }
        TableViewColumn {
            role: "age"
            title: "Ikäsarja"
            width: 100
        }
        TableViewColumn {
            role: "firstName"
            title: "Etunimi"
            width: 100
        }
        TableViewColumn {
            role: "lastName"
            title: "Sukunimi"
            width: 100
        }
        TableViewColumn {
            role: "place"
            title: "Paikkakunta"
            width: 100
        }
        TableViewColumn {
            role: "nationality"
            title: "Kansallisuus"
            width: 100
        }
        TableViewColumn {
            role: "team"
            title: "Joukkue"
            width: 100
        }
        model: libraryModel
    }
    ListModel {
        id: libraryModel
        ListElement {
            year: "2019"
            distance: "P50"
            gender: "Mies"
            age: "40"
            firstName: "Jussi"
            lastName: "Kujanen"
            place: "Keskihärmä"
            nationality: "Suomi"
            team: "TR3G"
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
