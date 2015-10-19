#include <QApplication>
#include <QQmlApplicationEngine>
#include "tesser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    tesser *t=new tesser();
    t->ocr();

    return app.exec();
}

