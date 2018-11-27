#include "listobjets.h"

void ListObjets::addObjet(Objet* _objet)
{
    listObjets.push_back(_objet);
}

int ListObjets::getSize()
{
    return listObjets.size();
}

QString ListObjets::getObjetNom(int _id)
{
    return listObjets[_id]->getNom();
}

bool ListObjets::exist(QString _objet)
{
    std::vector<Objet*>::iterator it;
    for(it = listObjets.begin(); it != listObjets.end(); it++)
    {
        if((*it)->getNom() == _objet) return true;
    }
    return  false;
}
