#include "objet.h"

Objet::Objet(){ }

Objet::Objet(QString _nom, unsigned int _quantite, std::vector<std::vector<QString>> _description)
{
    nom = _nom;
    quantite = _quantite;
    description = _description;
}

/*
 *  Ajout d'un paramètre
 */
void Objet::addParametre(QString _nom, QString _valeur)
{
    std::vector<QString> parametre;
    parametre.push_back(_nom);
    parametre.push_back(_valeur);

    description.push_back(parametre);
}

/*
 *  Getters
 */
QString Objet::getNom()
{
    return nom;
}

unsigned int Objet::getQuantite()
{
    return quantite;
}

std::vector<std::vector<QString>> Objet::getDescription()
{
    return description;
}

/*
 *  Setters
 */
void Objet::setNom(QString _nom)
{
    nom = _nom;
}

void Objet::setQuantite(unsigned int _quantite)
{
    quantite = _quantite;
}

void Objet::setDescription(std::vector<std::vector<QString>> _description)
{
    description = _description;
}
