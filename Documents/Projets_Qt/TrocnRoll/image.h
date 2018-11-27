#ifndef IMAGE_H
#define IMAGE_H

#include <QImage>
#include <QDate>

class Image
{
private:
    QImage photo;
    QString nom;
    QString description;
    QDate date;

public:
    Image();
    bool Sauvegarder();

    //Setter
    void setImage(QImage _image);
    void setNom(QString _nom);
    void setDescription(QString _desc);
    void setDate(QDate _date);

    //Getter
    QImage getImage();
    QString getNom();
    QString getDescription();
    QDate getDate();
};

#endif // IMAGE_H
