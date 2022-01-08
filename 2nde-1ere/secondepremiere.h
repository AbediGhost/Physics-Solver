#ifndef SECONDEPREMIERE_H
#define SECONDEPREMIERE_H

#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include "2nde-1ere/header/chimie2nde1ere.h"
#include "2nde-1ere/header/physique2nde1ere.h"

class SecondePremiere : public QWidget
{
    Q_OBJECT
public:
    SecondePremiere(QWidget *parent = 0);
private:
    //Fonctions
    void initialisation();
    void attribution();
    //Attributs
    QVBoxLayout *mainLay;
    QTabWidget *mainWid;
    Physique2nde1ere *Rosen;
    Chimie2nde1ere *Boyle;
};

#endif // SECONDEPREMIERE_H
