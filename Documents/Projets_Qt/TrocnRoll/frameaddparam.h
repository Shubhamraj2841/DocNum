#ifndef FRAMEADDPARAM_H
#define FRAMEADDPARAM_H

#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QtWidgets>

class FrameAddParam : public QWidget
{
    Q_OBJECT
private:
    QLineEdit nom;
    QLineEdit valeur;
    QPushButton supp;
public:
    FrameAddParam(QWidget *parent = nullptr);
    QString getNom();
    QString getValeur();
private slots:
    void suppression();
signals:
    void paramSupp(FrameAddParam* _widget);
};

#endif // FRAMEADDPARAM_H
