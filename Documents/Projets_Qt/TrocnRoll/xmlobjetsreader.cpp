#include "xmlobjetsreader.h"

XmlObjetsReader::XmlObjetsReader(ListObjets* _listObjets)
{
    listObjets = _listObjets;
}

bool XmlObjetsReader::read(QIODevice *_device)
{
    reader.setDevice(_device);

    if (reader.readNextStartElement())
    {
        qDebug() << reader.name();
        if (reader.name() == "objets") readListObjets();
        else reader.raiseError(QObject::tr("Mauvais fichier XML"));
    }
    return !reader.error();
}

void XmlObjetsReader::readListObjets()
{
    while(reader.readNextStartElement())
    {
        if(reader.name() == "objet") readObjet();
        else reader.skipCurrentElement();
    }
}

void XmlObjetsReader::readObjet()
{
    Q_ASSERT(reader.isStartElement() && reader.name() == "objet");

    Objet* obj = new Objet;

    while (reader.readNextStartElement())
    {
        if (reader.name() == "nom-objet") readNom(obj);
        else if (reader.name() == "quantite") readQuantite(obj);
        else if (reader.name() == "description") readDescription(obj);
        else reader.skipCurrentElement();
    }

    listObjets->addObjet(obj);
}

void XmlObjetsReader::readNom(Objet *_obj)
{
    Q_ASSERT(reader.isStartElement() && reader.name() == "nom-objet");

    QString nom = reader.readElementText();
    _obj->setNom(nom);
}

void XmlObjetsReader::readQuantite(Objet *_objet)
{
    Q_ASSERT(reader.isStartElement() && reader.name() == "quantite");

    QString quantite = reader.readElementText();
    _objet->setQuantite(quantite.toUInt());
}

void XmlObjetsReader::readDescription(Objet *_obj)
{
    Q_ASSERT(reader.isStartElement() && reader.name() == "description");

    std::vector<std::vector<QString>> listParametres;
    while(reader.readNextStartElement())
    {
        if(reader.name() == "parametre")
        {
            std::vector<QString> parametre;
            while(reader.readNextStartElement())
            {
                if(reader.name() == "nom-parametre")
                {
                    parametre.push_back(reader.readElementText());
                }
                else if(reader.name() == "valeur")
                {
                    parametre.push_back(reader.readElementText());
                }
                else reader.skipCurrentElement();
            }
            listParametres.push_back(parametre);
        }
        else reader.skipCurrentElement();
    }
    _obj->setDescription(listParametres);
}
