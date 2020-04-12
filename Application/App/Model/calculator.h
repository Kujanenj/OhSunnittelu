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
    /*!
     * \brief getBestTeam returns team with the lowest time
     * \param results <Team, Time>
     * \return best team
     */
    std::pair<QString,QString> getBestTeam(QVector<std::pair<QString,QString>> results);
    /**
     * @brief calculateAnalytics Calculates a analytics results partially
     * @param nonTeamResults
     * @return
     */
    QVector<QString> calculateAnalytics(QVector<QVector<QString>> nonTeamResults);



    QString calcWinnerSpeed(QVector<QVector<QString>> results);

    QString calcAverageSpeed(QVector<QVector<QString>> results);
    /*!
     * \brief TimeStringToInt turns a string based time to a float.
     * \param time
     * \return time as a float
     */
    float TimeStringToInt(QString time);

    QVector<std::pair<QString, float> > calculateGeneral(QVector<QVector<QString> > results, int index);

private:
    /*!
     * \brief IntTimeToString turns the float based time to stringbased
     * \param time
     * \return time as a string
     */
    QString IntTimeToString(float time);
};
}
#endif // CALCULATOR_H
