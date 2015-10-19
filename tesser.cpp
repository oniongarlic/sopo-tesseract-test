#include "tesser.h"
#include <QDebug>
#include <QImage>

#include <leptonica/allheaders.h>

tesser::tesser(QObject *parent) : QObject(parent)
{        
    m_tess=new tesseract::TessBaseAPI();
    m_tess->Init(NULL, "eng");
    m_tess->SetPageSegMode(tesseract::PSM_AUTO_OSD);
}

void tesser::ocr()
{
    char *text;
    QImage image("/home/milang/ocrtest2.jpg");

    qDebug() << image;

    QImage g=image.convertToFormat(QImage::Format_Grayscale8);
    qDebug() << g;

    m_tess->SetImage(g.bits(),
                     g.width(),
                     g.height(),
                     1,
                     g.bytesPerLine());

    m_tess->SetSourceResolution(300);
    m_tess->DetectOS(0);

    m_text.clear();

#if 1
    Boxa* boxes = m_tess->GetComponentImages(tesseract::RIL_BLOCK, true, NULL, NULL);
    printf("Found %d textline image components.\n", boxes->n);

    for (int i = 0; i < boxes->n; i++) {
       BOX* box = boxaGetBox(boxes, i, L_CLONE);
       m_tess->SetRectangle(box->x, box->y, box->w, box->h);
       text = m_tess->GetUTF8Text();
       int conf = m_tess->MeanTextConf();
       fprintf(stdout, "Box[%d]: x=%d, y=%d, w=%d, h=%d, confidence: %d, text: %s",
                       i, box->x, box->y, box->w, box->h, conf, text);
        if (conf>75)
            m_text.append(text);
    }
#else
    m_tess->Recognize(0);
    text=m_tess->GetUTF8Text();
    qDebug() << m_tess->MeanTextConf();

    m_text.append(text);
#endif

    qDebug() << m_text;

    m_tess->Clear();
}

tesser::~tesser()
{
    m_tess->End();
}
