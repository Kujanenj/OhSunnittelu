#include <iostream>
#include <QStringList>
#include <QProcess>
#include <QDebug>
#include <QFile>
using namespace std;

int main()
{
    QStringList arguments {"../../PythonApplication1/PythonApplication1/Request.py"};
    QProcess p;
    p.start("../../../../../../python.exe", arguments);
     QString p_stdout = p.readAllStandardOutput();

    p.waitForFinished();


        QString filename = "errors.txt";
        QFile file(filename);
        if (file.open(QIODevice::ReadWrite)) {
            QTextStream stream(&file);
            stream<<"Exit code "<<p.exitCode()<<endl
            <<p.readAllStandardError();

        }
        qDebug()<<"Done";

}
