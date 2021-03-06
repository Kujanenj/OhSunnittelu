#include "datacontroller.h"
#include <QDebug>

namespace Controller
{

DataController::DataController(std::shared_ptr<Model::DataModel> model, QObject* parent)
    : QObject(parent)
{
    dataModel_ = model;
    qDebug() << "DataController created";
}

DataController::~DataController()
{
    database_->removeData();
    qDebug() << "DataController removed";
}

void DataController::searchButtonClicked(QString startYear, QString endYear,
    QVector<QString> distances, QString gender, QVector<QString> ages, QString firstName,
    QString lastName, QString place, QString nationality, QString team, QString personalSearch)
{

    QString year;
    QString distance;
    QString age;
    qDebug() << "---------------------------";
    years_.clear();
    dataModel_->clearPars();
    database_->removeData();

    // Changes nationality text to match with all nationalities
    if (nationality == "All")
    {
        nationality = "0";
    }

    // Takes 2 nationality symbol letters
    nationality = nationality.left(2);

    QMap<QString, QString> parameters;

    int size = endYear.toInt() - startYear.toInt();

    parameters.insert("Kansalaisuus", nationality);
    parameters.insert("Sukupuoli", gender);
    parameters.insert("Etunimi", firstName);
    parameters.insert("Sukunimi", lastName);
    parameters.insert("Paikkakunta", place);
    parameters.insert("Joukkue", team);

    // MULTISEARCH FOR YEAR, DISTANCE, AGESERIES
    for (int i = 0; i <= size; i++)
    {

        // YEAR

        year = QString::number(startYear.toInt() + i);

        years_.append(year);
        parameters.insert("Vuosi", year);

        // DISTANCES LOOPING
        for (int j = 0; j < distances.size(); j++)
        {

             distance = distances.at(j);

            parameters.insert("Matka", distance);

            // AGES LOOPING
            for (int k = 0; k < ages.size(); k++)
            {

                age = ages.at(k);

                parameters.insert("Ikaluokka", age);

                try
                {

                    dataModel_->doRequest(parameters, parserConfig_);
                    dataModel_->insertData(personalSearch);
                    dataModel_->analytics(distances.at(j), year);
                    dataModel_->insertData("Analytics");
                }
                catch (QString msg)
                {
                    qDebug() << msg << endl << " continuing search";
                }
            }
        }
    }
    try
    {
        if (firstName == "" && lastName == "" && team == "" && place == "" && nationality == "0")
        {
            std::pair<QString, QString> years = { startYear, endYear };

          //  dataModel_->analytics(distances, years);
         //   dataModel_->insertData("Analytics");
        }
    }
    catch (...)
    {
        qDebug() << "Viduigsi meni! Ebin:D";
        delete this;
    }
}

void DataController::sortButtonClicked(
    QString selectedField, QString lowerBound, QString upperBound, QString rankSilder)
{
    QString command = "SELECT * FROM Results WHERE PLACE <= " + rankSilder + " AND TIME < "
        + upperBound + " AND TIME > " + lowerBound + " ORDER BY " + selectedField + " ASC";
    dataModel_->sortDataBase(command);
}

QVector<int> DataController::getGraphValues(QString graphtype, QString year, QString distance)
{
    QVector<int> values = {};
    int count_small_countries = 0;
    if (graphtype == "ajat")
    {
        QString query = "SELECT * FROM Results WHERE distance = '" + distance + "' AND year = '"
            + year + "' AND place < 11";
        QVector<QVector<QString>> results = dataModel_->searchDataBase(query);

        for (int i = 0; i < results.size(); i++)
        {
            float to_insert = (dataModel_->timeToFloat(results.at(i).at(2))) / 3600; // :D Ei olisi voinu tehä tätä omaksi funktioksi?
            //Kun esiintyy varmaan kymmenespaikkaa
            values.append(static_cast<int>(to_insert * 100));
        }
        return values;
    }
    else if (graphtype == "kansallisuudet")
    {
        QString query
            = "SELECT * FROM Results WHERE distance = '" + distance + "' AND year = '" + year + "'";
        QVector<std::pair<QString, float>> results = dataModel_->getPercanteges(query,9);
        for (int i = 0; i < results.size(); i++)
        {
            if (results.at(i).second < 20)
            {
                count_small_countries
                    = static_cast<int>(count_small_countries + results.at(i).second);
            }
            else
            {
                values.append(static_cast<int>(results.at(i).second));
            }
        }
        values.append(count_small_countries);
        return values;
    }

    else if (graphtype == "parhaat_m")
    {
        QString query = "SELECT * FROM Results WHERE distance = '" + distance
            + "' AND place = 1 ORDER BY year";
        QVector<QVector<QString>> results = dataModel_->searchDataBase(query);
        int last = getYears().at(0).toInt() - 1;
        for (int i = 0; i < results.size(); i++)
        {
            while (last + 1 < results.at(i).at(0).toInt())
            {
                // values.append(0);
                values.append(1);
                ++last;
            }
            float to_insert = (dataModel_->timeToFloat(results.at(i).at(2))) / 3600;
            values.append(static_cast<int>(to_insert * 100));
            last = results.at(i).at(0).toInt();
        }
        return values;
    }
    else if (graphtype == "parhaat_n")
    {
        QString query = "SELECT * FROM Results WHERE distance = '" + distance
            + "' AND placeN = 1 ORDER BY year";
        QVector<QVector<QString>> results = dataModel_->searchDataBase(query);
        int last = getYears().at(0).toInt() - 1;
        for (int i = 0; i < results.size(); i++)
        {
            while (last + 1 < results.at(i).at(0).toInt())
            {
                // values.append(0);
                values.append(1);
                ++last;
            }
            float to_insert = (dataModel_->timeToFloat(results.at(i).at(2))) / 3600;
            values.append(static_cast<int>(to_insert * 100));
            last = results.at(i).at(0).toInt();
        }
        return values;
    }
    else if (graphtype == "osallistujat")
    {
        QString query = "SELECT * FROM Results WHERE year = '" + year + "'";
        QVector<std::pair<QString, float>> results = dataModel_->getPercanteges(query,1);
        for (int i = 0; i < results.size(); i++)
        {
            if (!distances_.contains(results.at(i).first))
            {
                distances_.push_back(results.at(i).first);
            }
            values.append(static_cast<int>(results.at(i).second));
        }
        return values;
    }
    else if (graphtype == "top_5")
    {
        QString query = "SELECT * FROM Results WHERE place <= 5 ORDER BY distance";
        QVector<QVector<QString>> results = dataModel_->searchDataBase(query);
        QVector<QString> diff_distances;
        QVector<std::pair<QString, float>> distances;
        int amount = 0;
        float total = 0;
        float kilometers;
        for (int i = 0; i < results.size(); i++)
        {
            if (diff_distances.indexOf(results.at(i).at(1)) == -1)
            {
                diff_distances.push_back(results.at(i).at(1));
            }
        }
        for (auto dist : diff_distances)
        {
            for (int i = 0; i < results.size(); i++)
            {
                if (dist == results.at(i).at(1))
                {
                    total += dataModel_->timeToFloat(results.at(i).at(2)) / 3600;
                    amount += 1;
                }
            }
            if (dist.length() == 6)
            {
                dist.remove(3, 3);
            }
            kilometers = dist.remove(0, 1).toFloat();
            values.append(kilometers / (total / amount) * 10);
            total = 0;
            amount = 0;
        }
        return values;
    }
    else if(graphtype=="Teams"){
        for(int i =0; i<someTeamTimes_.size(); i++){
            float to_insert = (dataModel_->timeToFloat(someTeamTimes_.at(i))) / 3600;
            values.append(static_cast<int>(to_insert * 100));
        }
        return values;
    }
    return values;
}
QVector<QString> DataController::getGraphTypes(QString graphtype, QString year, QString distance)
{
    if (graphtype == "kansallisuudet")
    {
        QString query
            = "SELECT * FROM Results WHERE distance = '" + distance + "' AND year = '" + year + "'";
        QVector<std::pair<QString, float>> results = dataModel_->getPercanteges(query,9);

        QVector<QString> kansallisuudet;
        for (int i = 0; i < results.size(); i++)
        {
            if (results.at(i).second >= 20)
            {
                kansallisuudet.append(results.at(i).first);
            }
        }
        kansallisuudet.append("Other countries");
        return kansallisuudet;
    }
    else if (graphtype == "osallistujat")
    {
        QString query = "SELECT * FROM Results WHERE year = '" + year + "'";

        QVector<std::pair<QString, float>> results = dataModel_->getPercanteges(query,1);

        QVector<QString> osallistujat;
        for (int i = 0; i < results.size(); i++)
        {
            osallistujat.append(results.at(i).first);
        }
        return osallistujat;
    }
    else if (graphtype == "top_5")
    {
        QString query = "SELECT * FROM Results WHERE place <= 5 ORDER BY distance";

        QVector<QVector<QString>> results = dataModel_->searchDataBase(query);

        QVector<QString> matkat;
        QVector<QString>::iterator it;
        for (int i = 0; i < results.size(); i++)
        {
            it = std::find(matkat.begin(), matkat.end(), results.at(i).at(1));
            if (it == matkat.end())
            {
                matkat.push_back(results.at(i).at(1));
            }
        }
        return matkat;
    }
    return {};
}

QStringList DataController::getYears()
{
    return years_;
}

QStringList DataController::getDistances()
{
    QString query = "SELECT * FROM Results WHERE place <= 5 ORDER BY distance";

    QVector<QVector<QString>> results = dataModel_->searchDataBase(query);

    QStringList matkat;
    QStringList::iterator it;
    for (int i = 0; i < results.size(); i++)
    {
        it = std::find(matkat.begin(), matkat.end(), results.at(i).at(1));
        if (it == matkat.end())
        {
            matkat.push_back(results.at(i).at(1));
        }
    }
    return matkat;
}

void DataController::updateDropdownDistances()
{
    distances_.clear();
    QString query = "SELECT * FROM Results ";
    QVector<std::pair<QString, float>> results = dataModel_->getPercanteges(query,1);
    for (int i = 0; i < results.size(); i++)
    {
        if (!distances_.contains(results.at(i).first))
        {
            distances_.push_back(results.at(i).first);
        }
    }
}

QStringList DataController::getDropdownDistances()
{
    return distances_;
}

QStringList DataController::getTopTeams(QString year, QString distance)
{
    QVector<std::pair<QString,QString>> results=dataModel_->getBestTeams(10,year,distance); //Nimet
    return translateSomeNames(results);
}

QStringList DataController::translateSomeNames(QVector<std::pair<QString, QString> > result)
{
    someTeamTimes_.clear();
    QStringList returnList;
    for(int i = 0; i<result.size(); i++){
        returnList.push_back(result.at(i).first);
        someTeamTimes_.push_back(result.at(i).second);
    }
    return returnList;
}

} // Namespace controller
