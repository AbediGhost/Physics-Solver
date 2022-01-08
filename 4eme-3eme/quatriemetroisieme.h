#ifndef QUATRIEMETROISIEME_H
#define QUATRIEMETROISIEME_H

#include <QWidget>
#include <QTabWidget>
#include <QVBoxLayout>
#include "4eme-3eme/header/physik.h"
#include "4eme-3eme/header/fenprinc.h"

class QuatriemeTroisieme : public QWidget
{
    Q_OBJECT
public:
    QuatriemeTroisieme(QWidget *parent = 0);
private:
    //Fonctions privees
    void load();
    void setting();
    //Attributs prives
    QTabWidget *mainWid;
    Physike *physique;
    Chimike *chimie;
    QVBoxLayout *mainLay;
};

#endif // QUATRIEMETROISIEME_H
