import QtQuick 2.0
import QtQuick.Controls 2.13
import QtCharts 2.3
import QtQuick.Window 2.12
import QtQuick.Layouts 1.3

Item {

    function updateDropDown() {
        var years = DataController.getYears();
        var distances = DataController.getDropdownDistances();
        comboBoxSortYears.model = years;
        comboBoxSortDistances.model = distances;
    }

    function comboFunction() {
        top5averageSpeedChart.title = "Top 5 average speed "
        top10chart.title = "Top 10 teams " + comboBoxSortDistances.currentText + " in " + comboBoxSortYears.currentText

        distances.categories = DataController.getDistances()
        var keskinopeus_top_5 = DataController.getGraphValues("top_5", "2019", "P50")
        while(keskinopeudet.at(0)){
            keskinopeudet.remove(0)
        }
        for(var i = 0; i < keskinopeus_top_5.length; i++){
            keskinopeudet.append(keskinopeus_top_5[i] / 10)
        }

        var bestTeams = DataController.getTopTeams(comboBoxSortYears.currentText, comboBoxSortDistances.currentText)

        console.log(bestTeams)
        teams.categories = bestTeams
        var averageTimes = DataController.getGraphValues("Teams", "2019", "P50")
        while(averageTimeValues.at(0)){
            averageTimeValues.remove(0)
        }

        for(i = 0; i < averageTimes.length; ++i){
            averageTimeValues.append(averageTimes[i] / 100)
        }


        // TODO JEMPPU Laita averageTimes akselit toimimaa - Ajat saat averageTimes vectorista
        // Lisäksi korjaa toi keskinopeus chartti silleen, että se laskee ne top5 keskinopeudet
        // siltä väliltä mitä searchis haetaan - eli EI vain 5 vuoden väliä vaan esim 2012-2019
        // väliltä kaikkien matkojen keskinopeudet
    }

    Frame {
        id: frame
        anchors.topMargin: 49
        anchors.fill: parent

        ComboBox {
            id: comboBoxSortDistances
            x: -12
            y: -56
            scale: 1
            editable: false
            currentIndex: -1
            displayText: currentIndex === -1 ? "Distance" : currentText

            onActiveFocusChanged: {
                updateDropDown()
            }

            onActivated:  {
                comboFunction()
            }
        }

        ColumnLayout {
            id: columnLayout
            anchors.fill: parent

            ChartView {
                id: top5averageSpeedChart
                title: "Top 5 average speed"
                Layout.fillHeight: true
                Layout.fillWidth: true
                legend.alignment: Qt.AlignBottom
                antialiasing: true
                theme: ChartView.ChartThemeDark

                BarSeries {
                    id: keskinopeus
                    axisX: BarCategoryAxis { id:distances;
                        categories: ["P100", "P50" ] }

                    BarSet { id: keskinopeudet; label: "Average speed"; values: [21.24, 25] ; color: "blue"}
                }
            }

            ChartView {
                id: top10chart
                Layout.fillHeight: true
                Layout.fillWidth: true
                legend.alignment: Qt.AlignBottom
                title: "Top 10 teams"
                theme: ChartView.ChartThemeDark

                BarSeries {
                    id: top10teams
                    axisX: BarCategoryAxis {
                        id: teams
                        categories: ["Team 1", "Team 2" ]
                    }
                    axisY: BarCategoryAxis{
                        categories: ["0:00:00", "1:00:00", "2:00:00", "3:00:00", "4:00:00", "5:00:00"]
                        }
                    BarSet {
                        id: averageTimeValues
                        color: "#0000ff"
                        label: "Average times"
                    }
                }
                antialiasing: true
            }

        }

        ComboBox {
            id: comboBoxSortYears
            x: 134
            y: -56
            displayText: currentIndex === -1 ? "Years" : currentText

            onActiveFocusChanged: {
                updateDropDown()
            }

            onActivated:  {
                comboFunction()
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}D{i:7;anchors_height:325;anchors_width:625;anchors_x:6;anchors_y:1}
D{i:11;anchors_x:"-11";anchors_y:"-56"}D{i:2;anchors_height:100;anchors_width:100}
}
##^##*/
