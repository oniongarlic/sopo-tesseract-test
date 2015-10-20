#include <QApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <QFileSystemModel>
#include <QtGui/QDesktopServices>
#include <QStandardPaths>
#include "tesser.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);    
    QQmlApplicationEngine engine;
    QString p;

    qmlRegisterType<tesser>("org.tal.tesser", 1, 0, "TesseractOCR");

    QFileSystemModel *fsm = new QFileSystemModel(&engine);
    p=QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    fsm->setRootPath(p);
    fsm->setResolveSymlinks(true);

    engine.rootContext()->setContextProperty("filePicturesPath", p);
    engine.rootContext()->setContextProperty("fileSystemModel", fsm);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //tesser *t=new tesser();
    //t->ocr("/home/milang/ocrtest.png");

    return app.exec();
}

