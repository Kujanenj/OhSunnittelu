import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQml 2.3

Item {

    /*
    //YEAR FIELD
    ComboBox {
        id: fieldYear

        background: Rectangle {
            border.color:"white"
        }
        //YEAR OPTIONS
        model: ["Vuosi", "2019", "2018", "2017", "2016", "2015", "2014", "2013", "2012", "2011", "2010",
                    "2009", "2008", "2007", "2006", "2005", "2004", "2003", "2002", "2001", "2000",
                    "1999", "1998", "1997", "1996", "1995", "1994", "1993", "1992", "1991", "1990",
                    "1989", "1988", "1987", "1986", "1985", "1984", "1983", "1982", "1981", "1980",
                    "1979", "1978", "1977", "1976", "1975", "1974"]
        font.pointSize: 12
        width: 200
    }
    */

    //YEAR FIELD RANGE SLIDER VERSION
    RangeSlider {
        y:20

        id:fieldYear
        from: 1974
        to: 2019
        first.value:1974
        second.value: 2019
        stepSize: 1
        snapMode: "SnapAlways"

        Text {
            id: lowText
            text: parent.first.value
            anchors.left: parent.left
            anchors.bottom: parent.top
        }
        Text {
            id: hiText
            text: parent.second.value
            anchors.right: parent.right
            anchors.bottom: parent.top
        }
    }

    //DISTANCE FIELD
    ComboBox {
        id: fieldDistance

        background: Rectangle {
            border.color:"white"
        }
        //DISTANCE OPTIONS
        model: ["Matka", "P50", "V50", "P100", "P32", "V20", "V32", "V20jun", "P42", "V42", "V32",
                    "P20", "P30", "P44", "P60", "P62", "P25", "P32", "P35", "P45", "P52",
                    "P53", "P75", "V30", "V45", "V53", "V75"]

        font.pointSize: 12
        width: 200
        anchors.top: fieldYear.bottom
    }

    //GENDER FIELD
    RowLayout {
        Text {
            id: selected
            text: ""
            visible: false
            anchors.left: parent.right
        }

        id: fieldGender
        anchors.top: fieldDistance.bottom

        CheckBox {
            id: checkBoxBoth
            checked: false
            text: qsTr("Molemmat")

            onClicked: {
                parent: selected.text = "Molemmat"
                checkBoxFemale.checked = false
                checkBoxMale.checked = false
            }
        }
        CheckBox {
            id: checkBoxMale
            checked: false
            text: qsTr("Mies")

            onClicked: {
                parent: selected.text = "Mies"
                checkBoxFemale.checked = false
                checkBoxBoth.checked = false
            }
        }
        CheckBox {
            id: checkBoxFemale
            checked: false
            text: qsTr("Nainen")

            onClicked: {
                parent: selected.text = "Nainen"
                checkBoxBoth.checked = false
                checkBoxMale.checked = false
            }
        }

    }

    //AGE SERIES FIELD
    ComboBox {
        id: fieldAge

        background: Rectangle {
            border.color:"white"
        }
        //DISTANCE OPTIONS
        model: ["Ikäsarja", "Kaikki", "<35", "35", "40", "45", "50", "55", "60", "65", "70",
                    ">80",]

        font.pointSize: 12
        width: 200
        anchors.top: fieldGender.bottom
    }

    //FIRST NAME FIELD
    TextField {
        id: fieldFirstName

        background: Rectangle {
            border.color:"white"
        }
        font.pointSize: 12
        width: 200
        anchors.top: fieldAge.bottom
        placeholderText: "Etunimi"
        renderType: Text.QtRendering
        onTextChanged: backend.text = text
    }

    //LAST NAME FIELD
    TextField {
        id: fieldLastName

        background: Rectangle {
            border.color:"white"
        }
        font.pointSize: 12
        width: 200
        anchors.top: fieldFirstName.bottom
        placeholderText: "Sukunimi"
        renderType: Text.QtRendering
        onTextChanged: backend.text = text
    }

    //PLACE FIELD
    TextField {
        id: fieldPlace

        background: Rectangle {
            border.color:"white"
        }
        font.pointSize: 12
        width: 200
        anchors.top: fieldLastName.bottom
        placeholderText: "Paikkakunta"
        renderType: Text.QtRendering
        onTextChanged: backend.text = text
    }

    //NATIONALITY FIELD
    ComboBox {
        id: fieldNationality

        background: Rectangle {
            border.color:"white"
        }
        //YEAR OPTIONS
        model: ["Kansallisuus", "Kaikki"]
        font.pointSize: 12
        width: 200
        anchors.top: fieldPlace.bottom
    }

    //TEAM NAME FIELD
    TextField {
        id: fieldTeam

        background: Rectangle {
            border.color:"white"
        }
        font.pointSize: 12
        width: 200
        anchors.top: fieldNationality.bottom
        placeholderText: "Joukkue"
        renderType: Text.QtRendering
        onTextChanged: backend.text = text
    }

    //SEARCH BUTTON
    Button {
        id: buttonSearch
        font.pointSize: 12
        text: "Hae"
        anchors.top: fieldTeam.bottom
        onClicked: {
            //välitä hakukriteerit C++ puolelle

            backend.searchButtonClicked(fieldYear.first.value, fieldYear.second.value,
                                        fieldDistance.currentValue, selected.text,
                                        fieldFirstName.text, fieldLastName.text,
                                        fieldPlace.text, fieldNationality.currentValue,
                                        fieldTeam.text);
        }
    }
}
