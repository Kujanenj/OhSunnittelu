#ifndef CALCULATOR_H
#define CALCULATOR_H
#include <QString>
#include <QVector>

#define ROUNDF(f, c) (((float)((int)((f) * (c))) / (c)))

namespace Model {

/*!
 * \brief The Calculator class does diffrent kind of calculations.
 */
class Calculator
{
public:
    Calculator();
    /*!
     * \brief calcAverageTime Counts the average time based on number of results
     * \param results
     * \return h:min:sec.msec
     */
    QString calcAverageTime(QVector<QVector<QString>>results);
    /*!
     * \brief getMinMaxResults Gets the best and worst result
     * \param results
     * \return minMax
     */
    std::pair<QVector<QString>,QVector<QString>> getMinMaxResults(QVector<QVector<QString>> results);

    /**
     * @brief calculateAnalytics Calculates a analytics results partially
     * @param nonTeamResults
     * @return
     */
    QVector<std::pair<QString,QString>> getBestTeams(QVector<std::pair<QString,QString>>,int amount);
    QVector<QString> calculateAnalytics(QVector<QVector<QString>> nonTeamResults);



    QString calcWinnerSpeed(QVector<QVector<QString>> results);

    QString calcAverageSpeed(QVector<QVector<QString>> results);
    /*!
     * \brief TimeStringToInt turns a string based time to a float.
     * \param time
     * \return time as a float
     */
     static float TimeStringToInt(QString time);
    /*!
     * \brief calculatePercentagesGeneral calculates the percantegas of the key based on the number of results
     * \param results
     * \param index the result field index. E.g: index number 9 is countries
     * \return <Key, percantage>
     */
    QVector<std::pair<QString, float> > calculatePercentagesGeneral(QVector<QVector<QString> > results, int index);

private:
    /*!
     * \brief IntTimeToString turns the float based time to stringbased
     * \param time
     * \return time as a string
     */
    QString IntTimeToString(float time);


    struct compareTime{
        inline bool operator()(const std::pair<QString,QString>& first, const std::pair<QString,QString>& second)
        {
            return ( TimeStringToInt(first.second)<TimeStringToInt(second.second) );
        }
    };

};
}
#endif // CALCULATOR_H
