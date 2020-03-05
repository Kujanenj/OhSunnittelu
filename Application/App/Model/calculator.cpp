#include "calculator.h"
#include "QStringList"
#include <math.h>
namespace Model {


Calculator::Calculator()
{

}

QString Model::Calculator::calcAverageTime(QVector<QVector<QString> > results)
{
    if(results.size()==0){
        return "ERROR NO RESULTS I WONT COUNT JACK SHIT BUDDY!";
    }
    float totalTime=0;
  for(auto it:results){

      totalTime=totalTime+TimeStringToInt(it.at(2));
  }
  totalTime=totalTime/results.size();
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






}//namespace
