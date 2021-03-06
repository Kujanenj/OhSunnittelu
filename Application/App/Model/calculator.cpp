#include "calculator.h"
#include "QStringList"
#include <math.h>
#include <QMap>
#include <QDebug>
#include <algorithm>
namespace Model {


Calculator::Calculator()
{

}

QString Model::Calculator::calcAverageTime(QVector<QVector<QString> > results)
{
    int skipped=0;
    if(results.size()==0){
        return "ERROR NO RESULTS I WONT COUNT JACK SHIT BUDDY!";
    }
    float totalTime=0;
  for(auto it:results){

    if(it.at(2).length()>8){                                  //if the field numbers are too small..not a perfect check..
      totalTime=totalTime+TimeStringToInt(it.at(2));
  }
    else{
        skipped++;
    }
  }
  totalTime=totalTime/(results.size()-skipped);
  return IntTimeToString(totalTime);
}

float Calculator::TimeStringToInt(QString time)
{
    float total=0;
    QStringList splitted=time.split(":");
    total=splitted.at(0).toFloat()*60*60; //hours
    total=total+((splitted.at(1).toFloat()))*60; //minutes
    total=total+((splitted.at(2).split(".")).at(0)).toFloat(); // seconds
    total=total+((splitted.at(2).split(".").at(1)).toFloat())/100; //last 2 digits
    return total;
}

QString Calculator::IntTimeToString(float time)
{
    QString result="";
    float hours=std::floor(time / (60*60) );
    float minutes=std::floor( (time - hours*(60*60)) /60);
    float seconds =std::floor( (time - hours*(60*60) ) - (minutes*60) );
    float digits = ((time - hours*(60*60) )  - (minutes*60) - seconds) * 100;


    QString hoursString = QString::number(hours)   ;
    QString minutesString  = QString::number(minutes) ;
    QString secondsString  = QString::number(seconds) ;
    QString digitsString  = QString::number(digits)  ;

     if(minutesString.size()<2){
         minutesString="0"+minutesString;
     }
     if(secondsString.size()<2){
         secondsString="0"+secondsString;
     }
      digitsString=digitsString.left(2);
      result=hoursString+":"+minutesString+":"+secondsString+"."+digitsString;


    return result;


}

std::pair<QVector<QString>, QVector<QString> > Calculator::getMinMaxResults(QVector<QVector<QString> > results)
{

    std::pair<QVector<QString>,QVector<QString>> returnValues = {results.at(0),results.at(0)};

    for(auto it: results){
        if(TimeStringToInt(it.at(2)) < TimeStringToInt(returnValues.first.at(2))){
            returnValues.first=it;
        }
        if(TimeStringToInt(it.at(2)) > TimeStringToInt(returnValues.second.at(2))){
            returnValues.second=it;
        }

    }
    return returnValues;
}


QVector<std::pair<QString, QString> > Calculator::getBestTeams(QVector<std::pair<QString, QString> >results, int amount)
{
    if(amount ==1){ //This shit is way faster than actually sorting all the results
        QString returnTeam=results.at(0).first;
        QString returnTime =results.at(0).second;
        std::pair<QString,QString> returnPair = {returnTeam,returnTime};
        for(int i = 0; i<results.size(); i++){
            if(TimeStringToInt(results.at(i).second)<TimeStringToInt(returnTime)){
                returnTime=results.at(i).second;
                returnTeam=results.at(i).first;
            }
        }
        returnPair={returnTeam,returnTime};
        return {returnPair};
    }


    if(results.size()<amount){

       amount = results.size();
    }
    std::sort(results.begin(), results.end(),compareTime());
    QVector<std::pair<QString, QString> > returnvec;
    for(int i=0; i<amount; i++){
        returnvec.push_back(results.at(i));
    }

    return returnvec;
}

QVector<QString> Calculator::calculateAnalytics(QVector<QVector<QString>> nonTeamResults)
{
    QVector<QString> analyticsPARTIAL;
    QVector<QVector<QString>> analyticsFULL;

    analyticsPARTIAL.push_back(nonTeamResults.at(0).at(0));
    analyticsPARTIAL.push_back(nonTeamResults.at(0).at(1));             //Distance
    analyticsPARTIAL.push_back(calcAverageTime(nonTeamResults));        //Time
    analyticsPARTIAL.push_back(QString::number(nonTeamResults.size())); //participants
    analyticsPARTIAL.push_back(nonTeamResults.first().at(2));           //fastest time
    analyticsPARTIAL.push_back(nonTeamResults.last().at(2));            //slowest time
    analyticsPARTIAL.push_back(nonTeamResults.first().at(7));           //first
    analyticsPARTIAL.push_back(nonTeamResults.at(1).at(7));             //2nd
    analyticsPARTIAL.push_back(nonTeamResults.at(2).at(7));             //3rd
    analyticsPARTIAL.push_back(calcAverageSpeed(nonTeamResults));       // Average speed
    analyticsPARTIAL.push_back(calcWinnerSpeed(nonTeamResults));        // Winners speed

    return analyticsPARTIAL;
}


QVector<std::pair<QString, float> > Calculator::calculatePercentagesGeneral(QVector<QVector<QString> > results, int index)
{
    QMap<QString,int> unmodifiedCountries;
    for(int i = 0; i < results.size(); i++){
        if(unmodifiedCountries.contains(results.at(i).at(index))){
            unmodifiedCountries[results.at(i).at(index)]++;
        }
        else{
            unmodifiedCountries[results.at(i).at(index)]=1;
        }
    }

    int total = 0 ;
    QVector<std::pair<QString, float>> returnvec;
    for(QMap<QString,int>::iterator it = unmodifiedCountries.begin(); it!= unmodifiedCountries.end(); it++){
        total = total + it.value();
    }

    for(QMap<QString,int>::iterator it = unmodifiedCountries.begin(); it!= unmodifiedCountries.end(); it++){
       float test = it.value();

       float test2= test/total;

       float test3 = test2 * 100;
       //Tänne vois laittaa jotain precision juttui

        returnvec.push_back({it.key(),it.value()} );

    }

    return returnvec;

}


QString Calculator::calcWinnerSpeed(QVector<QVector<QString> > results)
{
    float winner_speed_in_float;

    QString distance = results.first().at(1);

    QString winner_time = results.first().at(2);

    if(distance == "P100" || distance == "V100") {
        distance = distance.mid(1,3);
    }
    else {
        distance = distance.mid(1,2);
    }

    float time_in_hours = TimeStringToInt(winner_time) / 3600;

    winner_speed_in_float = round((distance.toInt() / time_in_hours)*10)/10;

    QString winner_speed = QString::number(static_cast<double>(winner_speed_in_float));


    return winner_speed;
}

QString Calculator::calcAverageSpeed(QVector<QVector<QString> > results)
{
    QString averageTime = calcAverageTime(results);
    float average_speed_in_float;

    QString distance = results.first().at(1);

    if(distance == "P100" || distance == "V100") {
        distance = distance.mid(1,3);
    }
    else {
        distance = distance.mid(1,2);
    }

    float time_in_hours = TimeStringToInt(averageTime) / 3600;

    average_speed_in_float = round((distance.toInt() / time_in_hours)*10)/10;

    QString average_speed = QString::number(static_cast<double>(average_speed_in_float));



    return average_speed;
}







}//namespace
