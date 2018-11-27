#include "message.h"

Message::Message(QString _titre)
{
    titre = _titre;
}

QString Message::getTitre()
{
    return titre;
}

std::vector<Message> Message::getMessagesHist()
{
    std::vector<Message> result;

    QFile* xmlFile = new QFile("Ressources//historique.xml");

    if (xmlFile->open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QXmlStreamReader* xmlReader = new QXmlStreamReader(xmlFile);


        //Parse the XML until we reach end of it
        while(!xmlReader->atEnd() && !xmlReader->hasError()) {
                // Read next element
                QXmlStreamReader::TokenType token = xmlReader->readNext();
                //If token is just StartDocument - go to next
                if(token == QXmlStreamReader::StartDocument) {
                        continue;
                }
                //If token is StartElement - read it
                if(token == QXmlStreamReader::StartElement) {

                        if(xmlReader->name() == "message") {
                                continue;
                        }

                        if(xmlReader->name() == "titre") {
                            result.push_back(Message(xmlReader->readElementText()));
                        }
                }
        }

        if(xmlReader->hasError()) {
                qDebug() << xmlReader->errorString();
        }

        //close reader and flush file
        xmlReader->clear();
        xmlFile->close();
    }
    else qDebug() << "test";

    return result;
}
