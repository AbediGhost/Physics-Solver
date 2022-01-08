#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QListView>
#include <QStringListModel>
#include <QStringList>
#include <QModelIndex>
#include <QModelIndexList>
#include <QLabel>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>
#include <QApplication>
#include <QMessageBox>
#include "4eme-3eme/header/physik.h"
#include "4eme-3eme/header/fenprinc.h"
#include "4eme-3eme/quatriemetroisieme.h"
#include "2nde-1ere/secondepremiere.h"
#include "aboutus.h"
#include <fstream>
#include <Forum/forum.h>

class Fenetre : public QWidget//Fenetre principale heritant de QWidget
{
    Q_OBJECT
public:
    Fenetre();
public slots:
    void analyse();//SLOT qui va determiner le choix de l'utilisateur
    void checkRegistered();
    void loadData();
    void aboutUsShow();
    void registering();
private:
    //On declare d'abord les differents layout
    QHBoxLayout *HLay1;
    QHBoxLayout *HLay2;
    QHBoxLayout *HLay3;
    QHBoxLayout *HLay4;
    QVBoxLayout *VLay1;
    QVBoxLayout *VLay2;
    QVBoxLayout *PhysikeLay;
    QVBoxLayout *MainLay;
    //On declare ensuite les elements a afficher
    QLabel *accueil;
    QGroupBox *choix;
    QRadioButton *but1;
    QRadioButton *but2;
    QRadioButton *but3;
    QVBoxLayout *choixLay;
    QPushButton *valider;
    QPushButton *quitter;
    QPushButton *about;
    QLabel *droits;
    QTextEdit *infos;
    QTextEdit *description;
    QLabel *logo;
    QLabel *descriptIndic;
    //Declaration des trois issues possibles
    QuatriemeTroisieme *Lavoisier;
    SecondePremiere *Newton;
    Forum *Wahab;
    AboutUs *aPropos;
};

#endif // WIDGET_H
