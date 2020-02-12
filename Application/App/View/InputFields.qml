import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Controls.Styles 1.4
import QtQuick.Layouts 1.3
import QtQml 2.3

Item {

    //YEAR FIELD RANGE SLIDER VERSION
    RangeSlider {

        y:20
        width: 250
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
        textRole: "key"
        model: ListModel {
            id: distances
            ListElement { key: "50km perinteinen"; value: "P50" }
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

        font.pointSize: 11
        width: 250
        anchors.top: fieldYear.bottom
    }

    //GENDER FIELD
    RowLayout {
        Text {
            id: selected
            text: ""
            visible: false
        }

        id: fieldGender
        anchors.top: fieldDistance.bottom

        RadioButton {
            id: checkBoxBoth
            checked: true
            text: qsTr("Molemmat")

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

            onClicked: {
                parent: selected.text = "N"
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
        model: ["Ikäsarja", "kaikki", "<35", "35", "40", "45", "50", "55", "60", "65", "70",
                    ">80",]

        font.pointSize: 11
        width: 250
        anchors.top: fieldGender.bottom
    }

    //FIRST NAME FIELD
    TextField {
        id: fieldFirstName

        background: Rectangle {
            border.color:"white"
        }
        font.pointSize: 11
        width: 250
        anchors.top: fieldAge.bottom
        placeholderText: "Etunimi"
        renderType: Text.QtRendering
    }

    //LAST NAME FIELD
    TextField {
        id: fieldLastName

        background: Rectangle {
            border.color:"white"
        }
        font.pointSize: 11
        width: 250
        anchors.top: fieldFirstName.bottom
        placeholderText: "Sukunimi"
        renderType: Text.QtRendering
    }

    //PLACE FIELD
    TextField {
        id: fieldPlace

        background: Rectangle {
            border.color:"white"
        }
        font.pointSize: 11
        width: 250
        anchors.top: fieldLastName.bottom
        placeholderText: "Paikkakunta"
        renderType: Text.QtRendering
    }

    //NATIONALITY FIELD
    ComboBox {
        id: fieldNationality


        background: Rectangle {
            border.color:"white"
        }
        //YEAR OPTIONS
        model: ["Kansallisuus", "0", "AF - AFHANISTAN", "AX - ÅLAND ISLANDS", "AL - ALBANIA",
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
        font.pointSize: 11
        width: 250
        anchors.top: fieldPlace.bottom
    }

    //TEAM NAME FIELD
    TextField {
        id: fieldTeam

        background: Rectangle {
            border.color:"white"
        }
        font.pointSize: 11
        width: 250
        anchors.top: fieldNationality.bottom
        placeholderText: "Joukkue"
        renderType: Text.QtRendering
    }

    //SEARCH BUTTON
    Button {
        id: buttonSearch
        font.pointSize: 11
        text: "Hae"
        anchors.top: fieldTeam.bottom
        onClicked: {
            //välitä hakukriteerit C++ puolelle

            datamanager.searchButtonClicked(fieldYear.first.value, fieldYear.second.value,
                                        distances.get(fieldDistance.currentIndex).value, selected.text, fieldAge.currentText,
                                        fieldFirstName.text, fieldLastName.text,
                                        fieldPlace.text, fieldNationality.currentText,
                                        fieldTeam.text);
        }
    }
}
