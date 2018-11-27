#include "image.h"

Image::Image()
{

}


//Setter
void Image::setImage(QImage _image)
{
    photo = _image;
}

void Image::setNom(QString _nom)
{
    nom = _nom;
}

void Image::setDescription(QString _desc)
{
    description = _desc;
}

void Image::setDate(QDate _date)
{
    date = _date;
}

//Getter
QImage Image::getImage()
{
    return photo;
}

QString Image::getNom()
{
    return nom;
}

QString Image::getDescription()
{
    return description;
}

QDate Image::getDate()
{
    return date;
}
