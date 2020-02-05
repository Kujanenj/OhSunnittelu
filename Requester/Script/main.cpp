#include <iostream>
#include <QStringList>
#include <QProcess>
#include <QDebug>
#include <QFile>

#include <fstream>
#include <map>
#include <string>
using namespace std;

int main()
{

    // Luo mapin ja kirjoittaa filuun python scriptiä varten
    std::map<std::string, std::string> parameters;

    parameters.insert(std::pair<std::string, std::string>("dnn$ctr1025$Etusivu$ddlVuosi2x", "2019"));
    parameters.insert(std::pair<std::string, std::string>("dnn$ctr1025$Etusivu$ddlMatka2x", "P50"));
    parameters.insert(std::pair<std::string, std::string>("dnn$ctr1025$Etusivu$ddlIkaluokka2", "kaikki"));
    parameters.insert(std::pair<std::string, std::string>("dnn$ctr1025$Etusivu$ddlKansalaisuus2x", ""));
    parameters.insert(std::pair<std::string, std::string>("dnn$ctr1025$Etusivu$chkLstSukupuoli2", "kaikki"));
    parameters.insert(std::pair<std::string, std::string>("dnn$ctr1025$Etusivu$txtHakuEtunimi2", "Jussi"));
    parameters.insert(std::pair<std::string, std::string>("dnn$ctr1025$Etusivu$txtHakuSukunimi2", ""));
    parameters.insert(std::pair<std::string, std::string>("dnn$ctr1025$Etusivu$txtHakuPaikkakunta2", ""));
    parameters.insert(std::pair<std::string, std::string>("dnn$ctr1025$Etusivu$txtHakuJoukkue2", ""));

    std::ofstream parameterfile;
    parameterfile.open("../../Python_Script/parameters.txt");

    for(auto const& parameter : parameters) {
        parameterfile << parameter.first << ":" << parameter.second << "\n";
    }

    parameterfile.close();


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



