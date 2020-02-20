#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Controller/datamanager.h"
#include "Data/database.h"
#include "Model/listmodel.h"

/**
 * \mainpage Application
 *
 * \section Introduction
 *
 * This application is used to gather and display data from the finlandiahiihtosivu.
 *
 * All documentation is found inside the documents folder
 */
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    std::shared_ptr<DataBase> database=std::make_shared<DataBase>();
    try {
           database->connectToDataBase();
    } catch (QString msg) {
        qDebug()<<msg;
        return EXIT_FAILURE;
    }


    ListModel *model = new ListModel();

    engine.rootContext()->setContextProperty("myModel", model);
    engine.rootContext()->setContextProperty("database", &*database);


    //Creating backend and exposing data to the QML components instantiated by the QML engine
    Controller::Datamanager datamanager(database);
    engine.rootContext()->setContextProperty("datamanager", &datamanager);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
