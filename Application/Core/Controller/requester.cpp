#include "requester.h"

Requester::Requester()
{ 

}

QString Requester::DoRequest(QMap<QString, QString> config)
{

    parameters_=config;
    try {
        createJSON();
        startPScript();
    }  catch (QString msg) {
            qDebug()<<msg;
            std::move(msg);
    }

    return "";
}



void Requester::createJSON()
{
    QMapIterator<QString, QString> i(parameters_);
    while (i.hasNext()) {
        i.next();
        vmap_.insert(i.key(), i.value());
    }

    QJsonDocument json = QJsonDocument::fromVariant(vmap_);

    QString jsonfile = "params.json";
    QFile file1(jsonfile);
    if(file1.open(QIODevice::ReadWrite)) {
        file1.write(json.toJson());
        file1.close();
    }
}

void Requester::startPScript()
{
    QStringList arguments {"../../Apaplication/Core/Python_Script/main.py"};
    QProcess p;

    //p.start("python.exe", arguments); // WINDOWS VERSIO
    p.start("python", arguments); // LINUX VERSIO

    QString p_stdout = p.readAllStandardOutput();

    p.waitForFinished();

    if(p.exitCode() == 255) {
        throw QString("Your python path is probably wrong. Your current path is: " + QDir::currentPath());
    }
    if(p.exitCode() == 2) {
        throw QString("Your arguments path is wrong. ");
    }
    QString filename = "../../Application/Data/errors.txt";
    QFile file(filename);
    if (file.open(QIODevice::ReadWrite)) {
        QTextStream stream(&file);
        stream << "Exit code " << p.exitCode() << endl
        << p.readAllStandardError();
        qDebug() << p.readAllStandardError() << p.readAllStandardOutput();
    }
    qDebug()<<"Done";
}

