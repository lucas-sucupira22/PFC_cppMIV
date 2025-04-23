#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "CommandController.h"
#include "DownloadController.h"
#include "ReadingController.h"
#include "GeneralToolsController.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    CommandController *commandController = new CommandController(&app);
    qmlRegisterSingletonInstance("com.company.CommandController", 1, 0, "CommandController", commandController);

    DownloadController *downloadController = new DownloadController(&app);
    qmlRegisterSingletonInstance("com.company.DownloadController", 1, 0, "DownloadController", downloadController);

    ReadingController *readingController = new ReadingController(&app);
    qmlRegisterSingletonInstance("com.company.ReadingController", 1, 0, "ReadingController", readingController);

    GeneralToolsController *generalToolsController = new GeneralToolsController(&app);
    qmlRegisterSingletonInstance("com.company.GeneralToolsController", 1, 0, "GeneralToolsController", generalToolsController);

    QQmlApplicationEngine engine;
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("cppMIV", "Main");

    return app.exec();
}
