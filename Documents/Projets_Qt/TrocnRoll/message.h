#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <vector>
#include <QFile>
#include <QXmlStreamReader>
#include <QMessageBox>
#include <QDebug>

class Message
{
private:
    QString titre;

public:
    Message(QString _titre);
    QString getTitre();
    static std::vector<Message> getMessagesHist();
};

#endif // MESSAGE_H
