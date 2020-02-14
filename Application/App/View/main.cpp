#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <Controller/datamanager.h>
#include <QQmlContext>

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

    //Creating backend and exposing data to the QML components instantiated by the QML engine
    Datamanager datamanager;
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
