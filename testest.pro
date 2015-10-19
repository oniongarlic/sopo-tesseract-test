TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    tesser.cpp

RESOURCES += qml.qrc

LIBS += -ltesseract -llept

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    tesser.h

