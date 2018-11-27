#include "fichiermessages.h"

FichierMessages::FichierMessages()
{

}

//Getter
unsigned int FichierMessages::getFicID() { return ficID; }
std::string FichierMessages::getNmIE() { return nmIE; }
std::string FichierMessages::getNmIR() { return nmIR; }
unsigned int FichierMessages::getNumAuto() { return numAuto; }
struct tm FichierMessages::getDtOfSgtAuto() { return dtOfSgtAuto; }
unsigned int FichierMessages::getDureeValidAuto() { return dureeValidAuto; }
std::string FichierMessages::getMailDest() { return mailDest; }
std::string FichierMessages::getMailExp() { return mailExp; }
