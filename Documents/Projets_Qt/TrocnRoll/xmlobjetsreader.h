#ifndef XMLOBJETSREADER_H
#define XMLOBJETSREADER_H

#include <QIODevice>
#include <QXmlStreamReader>
#include <QDebug>
#include <QFile>

#include "listobjets.h"

class XmlObjetsReader
{
private:
    QXmlStreamReader reader;
    ListObjets* listObjets;
    void readListObjets();
    void readObjet();
    void readNom(Objet *_objet);
    void readQuantite(Objet *_objet);
    void readDescription(Objet *_objet);
public:
    XmlObjetsReader(ListObjets* _listObjets);
    bool read(QIODevice* _devise);
    QString errorString() const;
};

#endif // XMLOBJETSREADER_H
