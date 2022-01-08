#ifndef PHYSIK_H
#define PHYSIK_H

#include <QVBoxLayout>
#include <QPushButton>
#include <QFormLayout>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QTabWidget>
#include <QHBoxLayout>
#include <QTextEdit>
#include <QGroupBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QString>
#include <QDialog>
#include <QWidget>
#include "ps_element.h"

class Physike : public QWidget//On fait heriter de QWidget
{
    Q_OBJECT
public:
    Physike();
    void attributs();
    void attributs_haut();
    void attributs_bas();
    void attributs_param();
    void attributs_Conv();
    void clear();
    void remplirFluxForce();
    void remplirFluxCourant();
    void attributsCourants();
public slots:
    //Declaration des differents SLOTS
    void genererForce();
    void genererElec();
    void convertir();
    void effacer();
    void clearHaut();
    void clearBas();
    void retourZ();
private:
    void initialiser();
    //Declaration des Layout
    QVBoxLayout *PVLay1;
    QHBoxLayout *PHLay;
    QFormLayout *PFLay1;
    QFormLayout *PFLay2;
    QFormLayout *PFLay3;
    QFormLayout *PFLay4;
    QFormLayout *PFLay5;
    QFormLayout *PFLay6;
    QFormLayout *PFLay7;
    QFormLayout *PBLay1;
    //On declare les elements
    QSpinBox *PMasse;
    QDoubleSpinBox *PGravite;
    QDoubleSpinBox *PDistance;
    QDoubleSpinBox *Power;
    QDoubleSpinBox *Vitesse;
    QSpinBox *Force;
    QSpinBox *Temps;
    QPushButton *PSoluce;
    QDoubleSpinBox *PPoids;
    QSpinBox *TravailF;
    QSpinBox *Longueur;
    QDoubleSpinBox *PWP;
    QTabWidget *PZone;
    QWidget *PWork;
    QWidget *Courant;
    QWidget *Convert;
    QWidget *PSetting;
    QVBoxLayout *PFinLay;
    QTextEdit *PFlux;
    QHBoxLayout *Compo;
    QGroupBox *Facultatif;
    QFormLayout *Passible;
    QGroupBox *paramUnite;
    QRadioButton *uniteSi;
    QRadioButton *unitePerso;
    QVBoxLayout *uniteLayout;
    QVBoxLayout *PSettingLay;
    QLineEdit *edit1;
    QLineEdit *edit2;
    QLineEdit *edit3;
    QLineEdit *edit4;
    QFormLayout *unitePersoForm;
    QHBoxLayout *CLay;
    QVBoxLayout *CLay1;
    QVBoxLayout *CLay2;
    QVBoxLayout *CC;
    QFormLayout *CLay3;
    QFormLayout *CLay4;
    bool bPoids = false;
    bool bTravailF = false;
    bool bTravailP = false;
    bool bPower = false;
    bool bPower2 = false;
    bool bPower3 = false;
    bool bPoids2 = false;
    bool bTemps = false;
    bool bTemps2 = false;
    bool bVitesse = false;
    bool bVitesse2 = false;
    bool bVitesse3 = false;
    bool bTension = false;
    bool bIntensite = false;
    bool bETemps = false;
    bool bQuantite = false;
    bool bElectron = false;
    QDoubleSpinBox *CVitesseK;
    QDoubleSpinBox *CVitesseM;
    QDoubleSpinBox *CPowerW;
    QDoubleSpinBox *CPowerC;
    QPushButton *CConvertir;
    QPushButton *CClear;
    double coefVitesse;
    int coefPuissance;
    QFormLayout *Lay1Courant;
    QFormLayout *Lay2Courant;
    QPushButton *GenererCourant;
    QVBoxLayout *LayCourant;
    QSpinBox *CTemps;
    QDoubleSpinBox *CIntensite;
    QSpinBox *CQElectricite;
    QDoubleSpinBox *CResistance;
    QDoubleSpinBox *CTension;
    QDoubleSpinBox *CElectron;
    QPushButton *effaceHaut;
    QPushButton *effaceBas;
    QHBoxLayout  *layMiddle;
    QPushButton *RAZ;
};

#endif // PHYSIK_H
