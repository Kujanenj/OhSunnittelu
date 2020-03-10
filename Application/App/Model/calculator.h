#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QString>
#include <QVector>
namespace Model {


class Calculator
{
public:
    Calculator();

    QString calcAverageTime(QVector<QVector<QString>>results);
    float TimeStringToInt(QString time);
    QString IntTimeToString(float time);
    std::pair<QVector<QString>,QVector<QString>> getMinMaxResults(QVector<QVector<QString>> results);
    std::pair<QString,QString> getBestTeam();
private:

};
}
#endif // CALCULATOR_H
