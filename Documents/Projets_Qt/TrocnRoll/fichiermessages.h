#ifndef FICHIERMESSAGES_H
#define FICHIERMESSAGES_H

#include <string>
#include <ctime>

class FichierMessages
{
private:
    unsigned int ficID;             //Identifiant fichier
    std::string nmIE, nmIR;         //
    unsigned int numAuto;           //Numéro d'autorisation
    struct tm dtOfSgtAuto;          //
    unsigned int dureeValidAuto;    //
    std::string mailDest, mailExp;  //

public:
    FichierMessages();

    //Getter
    unsigned int getFicID();
    std::string getNmIE();
    std::string getNmIR();
    unsigned int getNumAuto();
    struct tm getDtOfSgtAuto();
    unsigned int getDureeValidAuto();
    std::string getMailDest();
    std::string getMailExp();

    //Setter

};

#endif // FICHIERMESSAGES_H
