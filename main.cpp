#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "controller.h"
#include "qqml.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<Controller>("Gravity",0,1,"Controller");
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
