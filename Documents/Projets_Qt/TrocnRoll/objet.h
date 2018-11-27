#ifndef OBJET_H
#define OBJET_H

#include <QString>
#include <vector>

class Objet
{
private:
    QString nom;
    unsigned int quantite;
    std::vector<std::vector<QString>> description;

public:
    Objet();
    Objet(QString _nom, unsigned int _quantite, std::vector<std::vector<QString>> _description);

    void addParametre(QString _nom, QString _valeur);

    //Getter / Setter
    QString getNom();
    unsigned int getQuantite();
    std::vector<std::vector<QString>> getDescription();

    void setNom(QString _nom);
    void setQuantite(unsigned int _quantite);
    void setDescription(std::vector<std::vector<QString>> _description);
};

#endif // OBJET_H
