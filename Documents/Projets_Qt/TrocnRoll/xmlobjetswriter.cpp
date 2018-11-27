#include "xmlobjetswriter.h"

XmlObjetsWriter::XmlObjetsWriter(){ }

void XmlObjetsWriter::setup(QIODevice* _device)
{
    writer.setDevice(_device);

    writer.writeStartDocument();
    writer.writeStartElement("objets");
    writer.writeEndDocument();
}

/*
void XmlObjetsWriter::write(QIODevice* _device, std::vector<Objet>* _objet)
{
    writer.setDevice(_device);
    writer.setAutoFormatting(true);

    writer.device()->reset();

    writer.writeStartDocument();
    writer.writeStartElement("objets");

    for(int i = 0; i < _objet->size(); i++)
    {
        writer.writeStartElement("objet");
        writer.writeTextElement("nom-objet", _objet[i].getNom());
        writer.writeTextElement("quantite", QString::number(_objet->getQuantite()));
        writer.writeStartElement("description");

        for(unsigned long long i = 0; i < _objet->getDescription().size(); i++)
        {
            writer.writeStartElement("parametre");
            writer.writeTextElement("nom-parametre", _objet->getDescription()[i][0]);
            writer.writeTextElement("valeur", _objet->getDescription()[i][1]);
            writer.writeEndElement();
        }

        writer.writeEndElement();
        writer.writeEndElement();
    }

    writer.writeEndElement();
    writer.writeEndDocument();
}
*/

void XmlObjetsWriter::write(QString _file, Objet* _objet)
{
    QDomDocument doc("xmlObjets");
    QFile file(_file);
    if (!file.open(QIODevice::ReadOnly))
    {
        return;
    }
    if (!doc.setContent(&file))
    {
        file.close();
        return;
    }
    file.close();

    QDomElement root = doc.documentElement();

    QDomElement newObjet = doc.createElement(QString("objet"));
    QDomElement newNomObjet = doc.createElement(QString("nom-objet"));
    QDomText newNomText = doc.createTextNode(_objet->getNom());
    QDomElement newQuantite = doc.createElement(QString("quantite"));
    QDomText newQuantiteText = doc.createTextNode(QString::number(_objet->getQuantite()));
    QDomElement newDescription = doc.createElement(QString("description"));

    for(unsigned long long i = 0; i < _objet->getDescription().size(); i++)
    {
        QDomElement newParametre = doc.createElement(QString("parametre"));
        QDomElement newNomParametre = doc.createElement(QString("nom-parametre"));
        QDomText newNomParametreText = doc.createTextNode(_objet->getDescription()[i][0]);
        QDomElement newValeurParametre = doc.createElement(QString("valeur"));
        QDomText newValeurParametreText = doc.createTextNode(_objet->getDescription()[i][1]);

        newNomParametre.appendChild(newNomParametreText);
        newValeurParametre.appendChild(newValeurParametreText);
        newParametre.appendChild(newNomParametre);
        newParametre.appendChild(newValeurParametre);
        newDescription.appendChild(newParametre);
    }

    newNomObjet.appendChild(newNomText);
    newQuantite.appendChild(newQuantiteText);
    newObjet.appendChild(newNomObjet);
    newObjet.appendChild(newQuantite);
    newObjet.appendChild(newDescription);
    root.appendChild(newObjet);

    if (!file.open(QIODevice::WriteOnly))
    {
        return;
    }
    QTextStream stream( &file );
    doc.save(stream,4,QDomDocument::EncodingFromDocument);

    file.close();
}
