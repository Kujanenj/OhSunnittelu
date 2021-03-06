import QtQuick 2.0
import QtQuick.Controls 2.13
import QtCharts 2.3
import QtQuick.Window 2.12

/**
  * represents charts tab in the UI
 */


Item {
    id: charts

    function updateDropDown() {
        var distances = DataController.getDropdownDistances()
        var years = DataController.getYears();
        comboBoxSortDistances.model = distances;
        comboBoxSortYears.model = years;
    }

    function comboFunction(){
        bestTimesChart.title = "Best times in distance " + comboBoxSortDistances.currentText
        distributionChart.title = "Distribution of athletes by country " +
                comboBoxSortDistances.currentText + " in " +
                comboBoxSortYears.currentText
        participantChart.title = "Participants on different trips in " + comboBoxSortYears.currentText
        bestskiersChart.title = "The difference between best skiers and winner " + comboBoxSortDistances.currentText +
                " in " + comboBoxSortYears.currentText

        years.categories=DataController.getYears();

        var ajat_values = DataController.getGraphValues("ajat",  comboBoxSortYears.currentText, comboBoxSortDistances.currentText);

        series.clear();
        var eka = ajat_values[0]
        for(var i = 0; i < ajat_values.length; i++){

            series.append(i+0.5, ((ajat_values[i]-eka)/100)*3)
        }
        var kansallisuudet_values = DataController.getGraphValues("kansallisuudet", comboBoxSortYears.currentText, comboBoxSortDistances.currentText);
        var kansallisuudet = DataController.getGraphTypes("kansallisuudet", comboBoxSortYears.currentText, comboBoxSortDistances.currentText)
        maat.clear()
        for(i = 0; i < kansallisuudet_values.length; i++){
            maat.append(kansallisuudet[i], kansallisuudet_values[i])
        }

        var osallistujat_values = DataController.getGraphValues("osallistujat", comboBoxSortYears.currentText, comboBoxSortDistances.currentText)
        var osallistuja = DataController.getGraphTypes("osallistujat", comboBoxSortYears.currentText, comboBoxSortDistances.currentText)
        osallistujat.clear()

        for(i = 0; i < osallistujat_values.length; i++){
            osallistujat.append(osallistuja[i], osallistujat_values[i])
        }

        var matkan_parhaat_m_values = DataController.getGraphValues("parhaat_m",comboBoxSortYears.currentText, comboBoxSortDistances.currentText)
        var matkan_parhaat_n_values = DataController.getGraphValues("parhaat_n", comboBoxSortYears.currentText, comboBoxSortDistances.currentText)
        var miehet = parhaat.at(0)
        var naiset = parhaat.at(1)

        while(miehet.at(0)){
            miehet.remove(0)
        }
        while(naiset.at(0)){
            naiset.remove(0)
        }

        for(i = 0; i < matkan_parhaat_m_values.length; i++){
            miehet.append(matkan_parhaat_m_values[i]/100)
        }
        for(i = 0; i < matkan_parhaat_n_values.length; i++){

            naiset.append(matkan_parhaat_n_values[i]/100)
        }

      }

    Frame {
        id: frame
        anchors.topMargin: 47
        anchors.fill: parent

        ChartView {
            id: bestskiersChart
            title: "The difference between best skiers and winner"
            antialiasing: true
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.right: parent.horizontalCenter
            anchors.bottom: parent.verticalCenter
            theme: ChartView.ChartThemeDark

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

            LineSeries {
                id: series
                name: "Times"

                axisX: CategoryAxis{
                    min: 0
                    max: 10

                    CategoryRange {
                        label: "1"
                        endValue: 1
                        }
                    CategoryRange {
                        label: "2"
                        endValue: 2
                        }
                    CategoryRange {
                        label: "3"
                        endValue: 3
                        }
                    CategoryRange {
                        label: "4"
                        endValue: 4
                        }
                    CategoryRange {
                        label: "5"
                        endValue: 5
                        }
                    CategoryRange {
                        label: "6"
                        endValue: 6
                    }
                    CategoryRange {
                        label: "7"
                        endValue: 7
                    }
                    CategoryRange {
                        label: "8"
                        endValue: 8
                    }
                    CategoryRange {
                        label: "9"
                        endValue: 9
                    }
                    CategoryRange {
                        label: "10"
                        endValue: 10
                    }

                }
                axisY: CategoryAxis{
                    min: 0
                    max: 1

                    CategoryRange{
                        label: "0:04:00"
                        endValue: .2
                    }

                    CategoryRange{
                        label: "0:08:00"
                        endValue: .4
                    }

                    CategoryRange{
                        label: "0:12:00"
                        endValue: .6
                    }
                    CategoryRange{
                        label: "0:16:00"
                        endValue: .8
                    }
                    CategoryRange{
                        label: "0:20:00"
                        endValue: 1
                    }
                }

                XYPoint { x: 0.5; y: 2.0 }
                XYPoint { x: 1.5; y: 2.3 }
                XYPoint { x: 2.5; y: 2.5 }
                XYPoint { x: 3.5; y: 3.4 }
                XYPoint { x: 4.5; y: 5.1 }
                XYPoint { x: 5.5; y: 6.0 }

            }

            ComboBox {
                id: comboBoxSortYears
                x: 140
                y: -56
                scale: 1
                editable: false
                currentIndex: -1
                displayText: currentIndex === -1 ? "Years" : currentText

                onActiveFocusChanged: {
                    updateDropDown()
                }

                onActivated:  {
                    comboFunction()
                }
            }
        }
        ChartView {
            id: participantChart
            title: "Participants on different trips"
            theme: ChartView.ChartThemeDark
            antialiasing: true
            anchors.top: parent.verticalCenter
            anchors.left: parent.horizontalCenter
            anchors.bottom: parent.bottom
            anchors.right: parent.right

            PieSeries {
                id: osallistujat
                PieSlice { label: "P50"; value: 24.9 }
                PieSlice { label: "P30"; value: 5.1 }
                PieSlice { label: "V50"; value: 70.0 }
            }
        }
        ChartView {
            id: distributionChart
            title: "Distribution of athletes by country"
            width: 625
            height: 325
            theme: ChartView.ChartThemeDark
            antialiasing: true
            anchors.top: parent.verticalCenter
            anchors.left: parent.left
            anchors.bottom: parent.bottom
            anchors.right: parent.horizontalCenter

            PieSeries {
                id: maat
                PieSlice { label: "Finnish"; value: 84.9 }
                PieSlice { label: "Sweden"; value: 5.1 }
                PieSlice { label: "Russian"; value: 10.0 }
            }
        }
        ChartView {
            title: "Best times in distance"
            id: bestTimesChart
            anchors.left: parent.horizontalCenter
            anchors.top: parent.top
            anchors.right: parent.right
            anchors.bottom: parent.verticalCenter
            width: 625
            height: 325
            legend.alignment: Qt.AlignBottom
            antialiasing: true
            theme: ChartView.ChartThemeDark

            BarSeries {
                id: parhaat
                axisX: BarCategoryAxis { id: years
                    categories: ["2010", "2011", "2012", "2013", "2014", "2015", "2016", "2017", "2018", "2019"  ] }
                axisY: BarCategoryAxis{
                    categories: ["0:00:00", "1:00:00", "2:00:00", "3:00:00", "4:00:00", "5:00:00"]
                    }
                BarSet { id: miehet; label: "Men"; values: [2, 2, 3.32, 4, 2.24, 4.12] ; color: "blue"}
                BarSet { id: naiset; label: "Women"; values: [5, 1, 2, 4, 1.12, 2] ; color: "red"}
            }
        }
    }
}

/*##^##
Designer {
    D{i:0;autoSize:true;height:480;width:640}
}
##^##*/
