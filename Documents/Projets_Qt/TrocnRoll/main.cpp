#include "mainwindow.h"
#include "main.h"

/**
 * @brief main
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    //Setup
    Setup();

    //Creation de l'application
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

/**
 * @brief Setup
 * @return 0 si OK, si > 0, erreur.
 */
int Setup()
{
    //Verifications existance fichiers et repertoires
    QDir currentDir(QDir::currentPath());
    QDir receptionDir("BoiteDeReception");
    QDir ressourcesDir("Ressources");
    QFile validationFile("Ressources\\validation.dtd");
    QFile historiqueFile("Ressources\\historique.xml");
    QFile contactsFile("Ressources\\contacts.xml");
    QFile objetsFile("Ressources\\objets.xml");

    /*
     * Tests existance repertoires
     */
    if(!receptionDir.exists()) currentDir.mkdir("BoiteDeReception");

    if(!ressourcesDir.exists()) qDebug() << "Le repertoire de Ressouces n'existe pas";

    /*
     * Tests existance fichiers
     */
    if(!validationFile.exists())
    {
        qDebug() << "Le Fichier DTD est manquant !";
    }

    if(!historiqueFile.exists())
    {
        qDebug() << "Le Fichier Historique est manquant !";
        historiqueFile.open(QIODevice::ReadWrite);
    }

    if(!contactsFile.exists())
    {
        qDebug() << "Le Fichier Contact est manquant !";
        contactsFile.open(QIODevice::ReadWrite);
    }
    if(!objetsFile.exists())
    {
        qDebug() << "Le Fichier Objets est manquant !";
        objetsFile.open(QIODevice::ReadWrite);
    }
    return 0;
}
