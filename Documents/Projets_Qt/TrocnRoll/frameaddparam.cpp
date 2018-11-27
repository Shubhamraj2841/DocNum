#include "frameaddparam.h"

FrameAddParam::FrameAddParam(QWidget *parent)
    : QWidget(parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    QHBoxLayout *layoutH = new QHBoxLayout(this);
    QVBoxLayout *layoutV = new QVBoxLayout;
    layoutH->addLayout(layoutV);

    nom.setPlaceholderText("Nom...");
    nom.setMinimumHeight(25);
    nom.setStyleSheet("background-color: white;"
                      "border: 1px solid grey;"
                      "border-radius: 5px;");
    valeur.setPlaceholderText("Valeur...");
    valeur.setMinimumHeight(25);
    valeur.setStyleSheet("background-color: white;"
                         "border: 1px solid grey;"
                         "border-radius: 5px;");
    layoutV->addWidget(&nom);
    layoutV->addWidget(&valeur);

    supp.setText("X");
    supp.setMinimumWidth(25);
    supp.setMaximumWidth(25);
    supp.setMinimumHeight(25);
    supp.setMaximumHeight(25);
    supp.setStyleSheet("QPushButton {"
                            "background: white;"
                            "color: #3a4055;"
                            "font-family: Arial;"
                            "border: 1px solid grey;"
                            "border-radius: 5px;"
                            "text-align: center;"
                       "}"
                       "QPushButton:hover {"
                            "background-color: #3a4055;"
                            "border-color: white;"
                            "color: white;"
                       "}");
    layoutH->addWidget(&supp);

    QObject::connect(&supp, SIGNAL(clicked()), this, SLOT(suppression()));

    this->setStyleSheet("background-color: white;");
}

QString FrameAddParam::getNom()
{
    return nom.text();
}

QString FrameAddParam::getValeur()
{
    return valeur.text();
}

void FrameAddParam::suppression()
{
    emit (paramSupp(this));
}
