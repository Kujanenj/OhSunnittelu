#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Controller/datacontroller.h"
#include "Data/database.h"
#include "Model/resultmodel.h"
#include "Model/analyticsmodel.h"
#include "Model/personalresultmodel.h"

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
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;


    std::shared_ptr<AnalyticsModel> analyticsmodel = std::make_shared<AnalyticsModel>();
    std::shared_ptr<ResultModel> resultmodel = std::make_shared<ResultModel>();
    std::shared_ptr<PersonalResultModel> personalresultmodel = std::make_shared<PersonalResultModel>();
    std::shared_ptr<DataBase> database=std::make_shared<DataBase>(resultmodel,analyticsmodel,personalresultmodel);
    std::shared_ptr<Model::DataModel> dataModel = std::make_shared<Model::DataModel>(database);
    try {
           database->connectToDataBase();
    } catch (QString msg) {
        qDebug()<<msg;
        return EXIT_FAILURE;
    }



    engine.rootContext()->setContextProperty("analyticsModel", &*analyticsmodel);
    engine.rootContext()->setContextProperty("resultModel", &*resultmodel);
    engine.rootContext()->setContextProperty("personalResultModel", &*personalresultmodel);
    engine.rootContext()->setContextProperty("database", &*database);


    //Creating backend and exposing data to the QML components instantiated by the QML engine
    Controller::DataController DataController(dataModel);
    engine.rootContext()->setContextProperty("DataController", &DataController);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
