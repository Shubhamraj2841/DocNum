#ifndef XMLOBJETSWRITER_H
#define XMLOBJETSWRITER_H

#include <QXmlStreamWriter>
#include <QDomDocument>
#include <QFile>
#include <QDebug>

#include "objet.h"

class XmlObjetsWriter
{
private:
    QXmlStreamWriter writer;
    void setup(QIODevice* _device);
public:
    XmlObjetsWriter();
    void write(QString _file, Objet* _objet);
};

#endif // XMLOBJETSWRITER_H
