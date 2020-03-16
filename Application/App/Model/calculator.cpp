#include "calculator.h"
#include "QStringList"
#include <math.h>
#include <QDebug>
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
  qDebug()<<"Skipped total of "<<skipped<<" while calculating average time";
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

std::pair<QString, QString> Calculator::getBestTeam(QVector<std::pair<QString,QString>> results)
{

    QString returnTeam=results.at(0).first;
    QString returnTime =results.at(0).second;
    std::pair<QString,QString> returnPair = {returnTeam,returnTime};
    for(int i = 0; i<results.size(); i++){
        if(TimeStringToInt(results.at(i).second)<TimeStringToInt(returnTime)){
            returnTime=results.at(i).second;
            returnTeam=results.at(i).first;
        }
    }
    return returnPair;
}






}//namespace
