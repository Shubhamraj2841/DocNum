#ifndef LISTOBJETS_H
#define LISTOBJETS_H

#include "objet.h"

class ListObjets
{
private:
    std::vector<Objet*> listObjets;
public:
    void addObjet(Objet* _objet);
    int getSize();
    QString getObjetNom(int _id);
    bool exist(QString _objet);
};

#endif // LISTOBJETS_H
