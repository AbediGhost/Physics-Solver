#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QApplication>
#include <QMessageBox>
#include "physik.h"
#include "fenprinc.h"
#include <fstream>

class Fenetre : public QWidget//Classe principale heritant de QWidget
{
    Q_OBJECT
public:
    Fenetre();
public slots:
    void analyse();//SLOT qui va determiner le choix de l'utilisateur
private:
    //On declare d'abord les differents layout
    QHBoxLayout *HLay1;
    QHBoxLayout *HLay2;
    QHBoxLayout *HLay3;
    QHBoxLayout *HLay4;
    QVBoxLayout *rim1;
    QVBoxLayout *VLay1;
    QVBoxLayout *VLay2;
    QVBoxLayout *PhysikeLay;
    QVBoxLayout *MainLay;
    //On declare ensuite les elements a afficher
    QLabel *accueil;
    QGroupBox *choix;
    QRadioButton *physique;
    QRadioButton *chimie;
    QPushButton *valider;
    QPushButton *quitter;
    QLabel *droits;
    QTextEdit *infos;
    QLabel *logo;
    //Declaration des deux issues possibles
    Physike *newton;
    Chimike *lavoisier;
};

#endif // WIDGET_H
