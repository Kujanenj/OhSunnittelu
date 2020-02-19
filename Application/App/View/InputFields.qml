import QtQuick 2.0
import QtQuick.Controls 2.12
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQml 2.3

Item {
    id: element

    //YEAR FIELD RANGE SLIDER VERSION

    //DISTANCE FIELD

    ColumnLayout {
        id: columnLayout
        anchors.fill: parent

        RowLayout {
            id: rowLayout
            x: 2
            width: 100
            height: 100

            Rectangle {
                id: rectangle1
                x: 3
                y: 3
                width: 130
                height: 35
                Layout.fillHeight: true
                Text {
                    id: element2
                    x: 0
                    y: 0
                    text: qsTr("Vuosi")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 19
                }
            }

            RangeSlider {

                width: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
                visible: true
                id:fieldYear
                from: 1974
                to: 2019
                first.value: 2019
                second.value: 2019
                stepSize: 1
                snapMode: "SnapAlways"

                Text {
                    id: lowText
                    text: parent.first.value
                    anchors.left: parent.left
                }
                Text {
                    id: hiText
                    text: parent.second.value
                    anchors.right: parent.right
                }
            }

        }

        RowLayout {
            id: rowLayout1
            width: 100
            height: 100
            Rectangle {
                id: rectangle2
                x: 3
                y: 3
                width: 130
                height: 35
                color: "#ffffff"
                Layout.fillHeight: true
                Layout.fillWidth: false
                Text {
                    id: element3
                    x: 0
                    y: 0
                    text: qsTr("Matka")
                    anchors.verticalCenter: parent.verticalCenter
                    font.pixelSize: 19
                }
            }

            ComboBox {
                id: fieldDistance
                Layout.fillHeight: true
                Layout.fillWidth: true
                clip: false
                wheelEnabled: false
                flat: false
                editable: false
                currentIndex: 0
                background: Rectangle {
                    border.color:"white"
                }

                //DISTANCE OPTIONS
                textRole: "key"
                model: ListModel {
                    id: distances
                    ListElement { key: "Kaikki matkat"; value: "kaikki"}
                    ListElement { key: "50km perinteinen"; value: "P50"}
                    ListElement { key: "50km vapaa"; value: "V50"}
                    ListElement { key: "100km perinteinen"; value: "P100"}
                    ListElement { key: "32km perinteinen"; value: "P32"}
                    ListElement { key: "20km vapaa"; value: "V20"}
                    ListElement { key: "32km vapaa"; value: "V32"}
                    ListElement { key: "20km vapaa, juniorit alle 16v"; value: "V20jun"}
                    ListElement { key: "42km perinteinen"; value: "P42"}
                    ListElement { key: "32km vapaa (2014)"; value: "V32"}
                    ListElement { key: "20km perinteinen (2014)"; value: "P20"}
                    ListElement { key: "30km perinteinen (2002-2005)"; value: "P30"}
                    ListElement { key: "44km perinteinen (2002)"; value: "P44"}
                    ListElement { key: "60km perinteinen (2003-2005)"; value: "P60"}
                    ListElement { key: "62km perinteinen (2006)"; value: "P62"}
                    ListElement { key: "25km perinteinen"; value: "P25"}
                    ListElement { key: "32km perinteinen"; value: "P32"}
                    ListElement { key: "35km perinteinen"; value: "P35"}
                    ListElement { key: "45km perinteinen"; value: "P45"}
                    ListElement { key: "52km perinteinen"; value: "P52"}
                    ListElement { key: "53km perinteinen"; value: "P53"}
                    ListElement { key: "75km perinteinen"; value: "P75"}
                    ListElement { key: "30km vapaa"; value: "V30"}
                    ListElement { key: "45km vapaa"; value: "V45"}
                    ListElement { key: "53km vapaa"; value: "V53"}
                    ListElement { key: "75km vapaa"; value: "V75"}

                }

                font.pointSize: 13
                //width: 250
                enabled: true
                hoverEnabled: true
                //flat: false
                //anchors.topMargin: 9
                visible: true
            }
        }

        RowLayout {
            id: rowLayout2
            width: 100
            height: 100
            Rectangle {
                id: rectangle3
                x: 3
                y: 3
                width: 130
                height: 35
                color: "#ffffff"
                Layout.fillHeight: true
                Text {
                    id: element4
                    x: 0
                    y: 0
                    text: qsTr("Sukupuoli")
                    font.pixelSize: 19
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            RowLayout {
                Text {
                    id: selected
                    text: ""
                    visible: true
                }

                id: fieldGender
                anchors.topMargin: 9
                visible: true

                RadioButton {
                    id: checkBoxBoth
                    checked: {
                        true
                        selected.text = "kaikki"
                    }
                    text: qsTr("Molemmat")
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    onClicked: {
                        parent: selected.text = "kaikki"
                        checkBoxFemale.checked = false
                        checkBoxMale.checked = false
                    }
                }
                RadioButton {
                    id: checkBoxMale
                    checked: false
                    text: qsTr("Mies")
                    Layout.fillHeight: true
                    Layout.fillWidth: true

                    onClicked: {
                        parent: selected.text = "M"
                        checkBoxFemale.checked = false
                        checkBoxBoth.checked = false
                    }
                }
                RadioButton {
                    id: checkBoxFemale
                    checked: false
                    text: qsTr("Nainen")
                    Layout.fillWidth: true
                    Layout.fillHeight: true

                    onClicked: {
                        parent: selected.text = "N"
                        checkBoxBoth.checked = false
                        checkBoxMale.checked = false
                    }
                }

            }
        }

        RowLayout {
            id: rowLayout3
            width: 100
            height: 100
            Layout.fillHeight: true
            Layout.fillWidth: true
            Rectangle {
                id: rectangle4
                x: 3
                y: 3
                width: 130
                height: 35
                color: "#ffffff"
                Layout.fillHeight: true
                Text {
                    id: element5
                    x: 0
                    y: 0
                    text: qsTr("Ikä")
                    font.pixelSize: 19
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            ComboBox {
                id: fieldAge
                Layout.fillHeight: true
                Layout.fillWidth: true
                currentIndex: 0
                background: Rectangle {
                    border.color:"white"
                }
                //DISTANCE OPTIONS
                //model: ["kaikki", "<35", "35", "40", "45", "50", "55", "60", "65", "70",
                    //">80",]

                textRole: "key"
                model: ListModel {
                    id: ages
                    ListElement { key: "Kaikki ikäsarjat"; value: "kaikki" }
                    ListElement { key: "Alle 35 vuotiaat"; value: "<35" }
                    ListElement { key: "Ikäsarja | 35"; value: "35" }
                    ListElement { key: "Ikäsarja | 40"; value: "40" }
                    ListElement { key: "Ikäsarja | 45"; value: "45" }
                    ListElement { key: "Ikäsarja | 50"; value: "50" }
                    ListElement { key: "Ikäsarja | 55"; value: "55" }
                    ListElement { key: "Ikäsarja | 60"; value: "60" }
                    ListElement { key: "Ikäsarja | 65"; value: "65" }
                    ListElement { key: "Ikäsarja | 70"; value: "70" }
                    ListElement { key: "Yli 80 vuotiaat"; value: ">80" }
                }

                font.pointSize: 13
                enabled: true
                width: 250
                anchors.topMargin: 9
                visible: true
            }
        }

        RowLayout {
            id: rowLayout4
            width: 100
            height: 100
            Rectangle {
                id: rectangle5
                x: 3
                width: 130
                height: 35
                color: "#ffffff"
                Layout.fillHeight: true
                Text {
                    id: element6
                    x: 0
                    y: 0
                    text: qsTr("Etunimi")
                    font.pixelSize: 19
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            TextField {
                id: fieldFirstName

                background: Rectangle {
                    border.color:"white"
                }
                font.pointSize: 14
                width: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
                anchors.topMargin: 9
                placeholderText: "Etunimi"
                renderType: Text.QtRendering
            }
        }

        RowLayout {
            id: rowLayout5
            width: 100
            height: 100
            Rectangle {
                id: rectangle6
                x: 3
                width: 130
                height: 35
                color: "#ffffff"
                Layout.fillHeight: true
                Text {
                    id: element7
                    x: 0
                    y: 0
                    text: qsTr("Sukunimi")
                    font.pixelSize: 19
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            TextField {
                id: fieldLastName

                background: Rectangle {
                    border.color:"white"
                }
                font.pointSize: 14
                width: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
                anchors.topMargin: 9
                visible: true
                placeholderText: "Sukunimi"
                renderType: Text.QtRendering
            }
        }

        RowLayout {
            id: rowLayout6
            width: 100
            height: 100
            Rectangle {
                id: rectangle7
                x: 3
                width: 130
                height: 35
                color: "#ffffff"
                Layout.fillHeight: true
                Text {
                    id: element8
                    x: 0
                    y: 0
                    text: qsTr("Paikkakunta")
                    font.pixelSize: 19
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            TextField {
                id: fieldPlace

                background: Rectangle {
                    border.color:"white"
                }
                font.pointSize: 14
                width: 250
                Layout.fillHeight: true
                Layout.fillWidth: true
                anchors.topMargin: 9
                placeholderText: "Paikkakunta"
                renderType: Text.QtRendering
            }
        }

        RowLayout {
            id: rowLayout7
            width: 100
            height: 100
            Rectangle {
                id: rectangle8
                x: 3
                width: 130
                height: 35
                color: "#ffffff"
                Layout.fillHeight: true
                Text {
                    id: element9
                    x: 0
                    y: 0
                    text: qsTr("Kansallisuus")
                    font.pixelSize: 19
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            ComboBox {
                id: fieldNationality
                Layout.fillHeight: true
                Layout.fillWidth: true
                textRole: qsTr("")

                background: Rectangle {
                    border.color:"white"
                }
                //YEAR OPTIONS
                model: ["kaikki", "AF - AFHANISTAN", "AX - ÅLAND ISLANDS", "AL - ALBANIA",
                    "DZ - ALGERIA", "AS - AMERICAN SAMOA", "AD - ANDORRA", "AO - ANGOLA",
                    "AI - ANGUILLA", "AQ - ANTARCTICA", "AG - ANTIGUA AND BARBUDA",
                    "AR - ARGENTINA", "AM - ARMENIA", "AW - ARUBA", "AU - AUSTRALIA",
                    "AT - AUSTRIA", "AZ - AZERBAIJAN", "BS - BAHAMAS", "BH -BAHRAIN",
                    "BD - BANGLADESH", "BB - BARBADOS", "BY - BELARUS", "BE - BELGIUM",
                    "BZ - BELIZE", "BJ - BENIN", "BM - BERMUDA", "BT - BHUTAN", "BO - BOLIVIA",
                    "BA - BOSNIA AND HERZEGOVINA", "BW - BOTSWANA", "BV - BOUVET ISLAND",
                    "BR - BRASIL", "IO - BRITISH INDIAN OCEAN TERRITORY", "BN - BRUNEI DARUSSALAM",
                    "BG - BULGARIA", "BF - BURKINA FASO", "BI - BURUNDI", "KH - CAMBODIA", "CM - CAMEROON",
                    "CA - CANADA", "CV - CAPE VERDE", "KY - CAYMAN ISLANDS", "CF - CENTRAL AFRICAN REPUBLIC",
                    "TD - CHAD", "CL - CHILE", "CN - CHINA", "CX - cHRISTMAS ISLAND", "CC - COCOS (KEELING) ISLANDS",
                    "CO - COLOMBIA", "KM - COMOROS", "CG - CONGO", "CD - CONGO", "CK - COOK ISLANDS",
                    "CR - COSTA RICA", "CI - COTE DIVOIRE", "HR - CROATIA", "CU - CUBA", "CY - CYPRUS",
                    "CZ - CZECH REPUBLIC", "DK - DENMARK", "DJ -DJIBOUTI", "DM - DOMINICA",
                    "DO - DOMINICAN REPUBLIC", "EC -ECUADOR", "EG - EGYPT", "SV - EL SALVADOR",
                    "GQ - EQUATORIAL GUINEA", "ER - ERITREA", "EE - ESTONIA", "ET - ETHIOPIA",
                    "FK - FALKLAND ISLANDS (MALVINAS)", "FO - FAROE ISLANDS", "FJ - FIJI",
                    "FI - FINLAND", "FR - FRANCE", "GF - FRENCH GUIANA", "PF - FRENCH POLYNESIA",
                    "TF - FRENCH SOUTHERN TERRITORIES", "GA - GABON", "GM - GAMBIA",
                    "GE - GEORGIA", "DE - GERMANY", "GH - GHANA", "GI - GIBRALTAR",
                    "GR - GREECE", "GL - GREENLAND", "GD - GRENADA", "GP - GUADELOUPE",
                    "GU - GUAM", "GT - GUATEMALA", "GG - GUERNSEY", "GN - GUINEA",
                    "GW - GUINEA-BISSAU", "GY - GUYANA", "HT - HAITI",
                    "HM - Heard Island and Mcdonald Islands",
                    "VA - HOLY SEE (VATICAN CITY STATE)", "HN - HONDURAS",
                    "HK - HONG KONG", "HU - HUNGARY", "IS - ICELAND", "IN - INDIA",
                    "ID - INDONESIA", "IR - IRAN", "IQ - IRAQ", "IE - IRELAND",
                    "IM - ISLE OF MAN", "IL - ISRAEL", "IT - ITALY", "JM - JAMAICA", "JP - JAPAN",
                    "JE - JERSEY", "JO - JORDAN", "KZ - KAZAKHSTAN", "KE - KENYA",
                    "KI - KIRIBATI", "KP - KOREA, Democratic People's Republic of",
                    "KR - KOREA, REPUBLIC OF", "KW - KUWAIT", "KG - KYRGUZSTAN",
                    "LA - LAO PEOPLE'S DEMOCRATIC REPUBLIC", "LV - LATVIA", "LB - LEBANON",
                    "LS - LESOTHO", "LR - LIBERIA", "LY - LIBYAN ARAB JAMAHIRIYA",
                    "LI - LIECHTENSTEIN", "LT - LITHUANIA", "LU - LUXEMBOURG", "MO - MACAO",
                    "MK - MACEDONIA, The former Yogoslaw republic of", "MG - MADAGASCAR",
                    "MW - MALAWI", "MY - MALAYSIA", "MV - MALDIVES" ,"ML - MALI", "MT - MALTA",
                    "MH - MARSHALL ISLANDS", "MQ -MARTINIQUE", "MR - MAURITANIA",
                    "MU - MAURITIUS", "YT - MAYOTTE", "MX - MEXICO" ,"FM - MICRONESIA, FEDERATED STATES OF ",
                    "MD - MOLDOVA, REPUBLIC OF", "MC - MONACO", "MN - MONGOLIA", "MS - MONTSERRAT",
                    "MA - MOROCCO", "MZ - MOZAMBIQUE", "MM - MYANMAR", "NA - NAMIBIA",
                    "NR - NAURU", "NP - NEPAL", "NL - NETHERLANDS", "AN - NETHERLANDS ANTILLES",
                    "NC - NEW CALEDONIA", "NZ - NEW ZEALAND", "NI - NICARAGUA", "NE - NIGER",
                    "NG - NIGERIA", "NU - NIUE", "NF - NORFOLK ISLAND",
                    "MP - NORTHERN MARIANA ISLANDS", "NO - NORWAY", "OM - OMAN",
                    "PK - PAKISTAN" ,"PW - PALAU", "PS - PALESTINAN TERRITORY, OCCUPIED",
                    "PA - PANAMA", "PG - PAPUA NEW GUINEA", "PY - PARAGUAY", "PE - PERU",
                    "PH - PHILIPPINES", "PN - PITCAIRN", "PL - POLAND", "PT - PORTUGAL",
                    "PR - PUERTO RICO", "QA - QATAR", "RE - REUNION", "RO - ROMANIA",
                    "RU - RUSSIAN FEDERATION", "RW - RWANDA", "SH - SAINT HELENA",
                    "KN - SAINT KITTS AND NEVIS", "LC - SAINT LUCIA", "PM - SAINT PIERRE AND MIQUELON",
                    "VC - SAINT VINCENT AND THE GRENADINES", "WS - SAMOA", "SM - SAN MARINO",
                    "ST - SAO TOME AND PRINCIPE", "SA - SAUDI ARABIA", "SN - SENEGAL",
                    "CS - SERBIA AND MONTENEGRO", "SC- SEYCHELLES", "SL - SIERRA LEONE",
                    "SG - SINGAPORE", "SK - SLOVAKIA", "SI - SLOVENIA", "SB - SOLOMON ISLANDS",
                    "SO - SOMALIA", "ZA - SOUTH AFRICA", "GS - South Georgia and the South Sandwich Islands",
                    "ES - SPAIN", "LK - SRI LANKA", "SD - SUDAN", "SR - SURINAME",
                    "SJ - SVALBARD AND JAN MAYEN", "SZ - SWAZILAND", "SE - SWEDEN",
                    "CH - SWITZERLAND", "SY - SYRIAN ARAB REPUBLIC",
                    "TW - TAIWAN, PROVINCE OF CHINA", "TJ - TAJIKISTAN",
                    "TZ - TANZANIA, UNITED REPUBLIC OF", "TH - THAILAND", "TL - TIMOR-LESTE",
                    "TG - TOGO", "TK - TOKELAU", "TO - TONGA", "TT - TRINIDAD AND TOBAGO",
                    "TN - TUNISIA", "TR - TURKEY", "TM - TURKMENISTAN",
                    "TC - TURKS AND CAICOS ISLANDS", "TV - TUVALU", "UG - UGANDA", "UA - UKRAINE",
                    "AE - UNITED ARAB EMIRATES", "GB - UNITED KINGDOM", "US - UNITED STATES",
                    "UM - United States Minor Outlying Island", "UY - URUGUAY", "UZ -UZBEKISTAN",
                    "VU - VANUATU", "VA - Vatican City State see HOLY SEE", "VE -VENEZUELA",
                    "VN - VIET NAM", "VG - VIRGIN ISLANDS, BRITISH", "VI - VIRGIN ISLANDS, U.S",
                    "WF - WALLIS AND FUTUNA", "EH - WESTERN SAHARA", "YE - YEMEN",
                    "ZR - ZAIRE see CONGO", "ZM - ZAMBIA", "ZW - ZIMBABWE"]
                font.pointSize: 15
                anchors.topMargin: 9
            }
        }

        RowLayout {
            id: rowLayout8
            width: 100
            height: 100
            Rectangle {
                id: rectangle9
                x: 3
                width: 130
                height: 35
                color: "#ffffff"
                Layout.fillHeight: true
                Text {
                    id: element10
                    x: 0
                    y: 0
                    text: qsTr("Joukkue")
                    font.pixelSize: 19
                    anchors.verticalCenter: parent.verticalCenter
                }
            }

            TextField {
                id: fieldTeam

                background: Rectangle {
                    border.color:"white"
                }
                font.pointSize: 14
                width: 250
                height: 30
                Layout.fillHeight: true
                Layout.fillWidth: true
                anchors.topMargin: 9
                placeholderText: "Joukkue"
                renderType: Text.QtRendering
            }
        }

        RowLayout {
            id: rowLayout9
            width: 100
            height: 100

            Button {
                id: buttonSearch
                x: 3
                font.pointSize: 11
                text: "Hae"
                anchors.topMargin: 9
                visible: true
                onClicked: {
                    //välitä hakukriteerit C++ puolelle

                    datamanager.searchButtonClicked(fieldYear.first.value, fieldYear.second.value,
                                                    distances.get(fieldDistance.currentIndex).value, selected.text,
                                                    ages.get(fieldAge.currentIndex).value,
                                                    fieldFirstName.text, fieldLastName.text,
                                                    fieldPlace.text, fieldNationality.currentText,
                                                    fieldTeam.text);
                    bar.currentIndex = 1
                    myModel.updateModel()
                }
            }
        }


    }

    //GENDER FIELD

    //AGE SERIES FIELD

    //FIRST NAME FIELD

    //LAST NAME FIELD

    //PLACE FIELD

    //NATIONALITY FIELD

    //TEAM NAME FIELD

    //SEARCH BUTTON
















}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:1;anchors_height:100;anchors_width:100}
}
##^##*/
