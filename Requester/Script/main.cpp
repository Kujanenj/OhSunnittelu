#include <iostream>
#include <QStringList>
#include <QProcess>
#include <QDebug>
#include <QFile>

#include <QJsonDocument>
#include <string>

using namespace std;

int main()
{

    QMap<QString, QString> parameters;
    QVariantMap vmap;

    parameters.insert("dnn$ctr1025$Etusivu$ddlVuosi2x", "2019");
    parameters.insert("dnn$ctr1025$Etusivu$ddlMatka2x", "P50");
    parameters.insert("dnn$ctr1025$Etusivu$ddlIkaluokka2", "kaikki");
    parameters.insert("dnn$ctr1025$Etusivu$ddlKansalaisuus2x", "");
    parameters.insert("dnn$ctr1025$Etusivu$chkLstSukupuoli2", "kaikki");
    parameters.insert("dnn$ctr1025$Etusivu$txtHakuEtunimi2", "Veikko");
    parameters.insert("dnn$ctr1025$Etusivu$txtHakuSukunimi2", "");
    parameters.insert("dnn$ctr1025$Etusivu$txtHakuPaikkakunta2", "");
    parameters.insert("dnn$ctr1025$Etusivu$txtHakuJoukkue2", "");

    QMapIterator<QString, QString> i(parameters);
    while (i.hasNext()) {
        i.next();
        vmap.insert(i.key(), i.value());
    }

    QJsonDocument json = QJsonDocument::fromVariant(vmap);

    QString jsonfile = "params.json";
    QFile file1(jsonfile);
    if(file1.open(QIODevice::ReadWrite)) {
        file1.write(json.toJson());
        file1.close();
    }

    QStringList arguments {"../../Python_Script/main.py"};
    QProcess p;

    p.start("python.exe", arguments); // WINDOWS VERSIO
    //p.start("python", arguments); // LINUX VERSIO

    QString p_stdout = p.readAllStandardOutput();

    p.waitForFinished();


        QString filename = "errors.txt";
        QFile file(filename);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream << "Exit code " << p.exitCode() << endl
            << p.readAllStandardError();
            qDebug() << p.readAllStandardError() << p.readAllStandardOutput();
        }
        qDebug()<<"Done";

}



