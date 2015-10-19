#ifndef TESSER_H
#define TESSER_H

#include <QObject>
#include "tesseract/baseapi.h"
#include "tesseract/ocrclass.h"

class tesser : public QObject
{
    Q_OBJECT
public:
    explicit tesser(QObject *parent = 0);
    Q_INVOKABLE void ocr();
    ~tesser();

signals:

public slots:

private:
    tesseract::TessBaseAPI* m_tess;
    QString m_text;
};

#endif // TESSER_H
