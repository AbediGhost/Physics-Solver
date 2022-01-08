#include "4eme-3eme/header/physik.h"

Physike::Physike()
{
    setWindowTitle("Physique-Abedi_Technology");
    initialiser();
    attributs();
    setLayout(Compo);
    QObject::connect(PSoluce,SIGNAL(clicked()),this,SLOT(genererForce()));
    QObject::connect(GenererCourant,SIGNAL(clicked()),this,SLOT(genererElec()));
    QObject::connect(CConvertir,SIGNAL(clicked(bool)),this,SLOT(convertir()));
    QObject::connect(CClear,SIGNAL(clicked()),this,SLOT(effacer()));
    QObject::connect(effaceBas,SIGNAL(clicked()),this,SLOT(clearBas()));
    QObject::connect(effaceHaut,SIGNAL(clicked(bool)),this,SLOT(clearHaut()));
    QObject::connect(RAZ,SIGNAL(clicked()),this,SLOT(retourZ()));
}
void Physike::initialiser()//Fonction qui se charge d'initialiser les pointeurs
{
    PVLay1 = new QVBoxLayout;
    PSetting = new QWidget;
    PFLay1 = new QFormLayout;
    PFLay2 = new QFormLayout;
    PFLay3 = new QFormLayout;
    PHLay = new QHBoxLayout;
    PBLay1 = new QFormLayout;
    PMasse = new QSpinBox;
    PGravite = new QDoubleSpinBox;
    PDistance = new QDoubleSpinBox;
    Power = new QDoubleSpinBox;
    Temps = new QSpinBox;
    Vitesse = new QDoubleSpinBox;
    Longueur = new QSpinBox;
    Force = new QSpinBox;
    PSoluce = new QPushButton;
    PFinLay = new QVBoxLayout;
    PPoids = new QDoubleSpinBox;
    TravailF = new QSpinBox;
    PWP = new QDoubleSpinBox;
    Facultatif = new QGroupBox;
    Passible = new QFormLayout;
    PZone = new QTabWidget(this);
    Convert = new QWidget;
    PWork = new QWidget;
    PFlux = new QTextEdit;
    Compo = new QHBoxLayout;
    paramUnite = new QGroupBox;
    uniteSi = new QRadioButton;
    unitePerso = new QRadioButton;
    uniteLayout = new QVBoxLayout;
    PSettingLay = new QVBoxLayout;
    edit1 = new QLineEdit;
    edit2 = new QLineEdit;
    edit3 = new QLineEdit;
    edit4 = new QLineEdit;
    unitePersoForm = new QFormLayout;
    CLay = new QHBoxLayout;
    CLay1 = new QVBoxLayout;
    CLay2 = new QVBoxLayout;
    CLay3 = new QFormLayout;
    CLay4 = new QFormLayout;
    CVitesseK = new QDoubleSpinBox;
    CVitesseM = new QDoubleSpinBox;
    CPowerW = new QDoubleSpinBox;
    CPowerC = new QDoubleSpinBox;
    CConvertir = new QPushButton;
    CClear = new QPushButton;
    CC = new QVBoxLayout;
    coefVitesse = 3.6;
    coefPuissance = 735;
    Courant = new QWidget;
    Lay1Courant = new QFormLayout;
    Lay2Courant = new QFormLayout;
    GenererCourant = new QPushButton;
    LayCourant = new QVBoxLayout;
    CTemps = new QSpinBox;
    CIntensite = new QDoubleSpinBox;
    CQElectricite = new QSpinBox;
    CResistance = new QDoubleSpinBox;
    CTension = new QDoubleSpinBox;
    CElectron = new QDoubleSpinBox;
    effaceHaut = new QPushButton;
    effaceBas = new QPushButton;
    layMiddle = new QHBoxLayout;
    PFLay7 = new QFormLayout;
    RAZ = new QPushButton;
}

void Physike::attributs()//On personalise les differents elements
{
    attributs_haut();
    attributs_bas();
    attributsCourants();
    attributs_Conv();
    attributs_param();
    Courant->setLayout(LayCourant);
    PFlux->setReadOnly(true);
    layMiddle->addWidget(PSoluce);
    layMiddle->addWidget(effaceHaut);
    layMiddle->addWidget(effaceBas);
    layMiddle->addWidget(RAZ);
    PSoluce->setText("Générer");
    effaceHaut->setText("effacer en Haut");
    effaceBas->setText("effacer en Bas");
    RAZ->setText("RAZ");
    PHLay->addLayout(PFLay1);
    PHLay->addLayout(PFLay7);
    PVLay1->addLayout(PHLay);
    PVLay1->addLayout(layMiddle);
    PVLay1->addLayout(PBLay1);
    PSetting->setLayout(PSettingLay);
    PWork->setLayout(PVLay1);
    PZone->addTab(PWork,"Forces");
    PZone->addTab(Courant,"Courant");
    PZone->addTab(Convert,"Convertisseur");
    Compo->addWidget(PFlux);
    Compo->addWidget(PZone);
}

void Physike::attributs_haut()
{
    PMasse->setSuffix(" Kg");
    PMasse->setRange(0,20000);
    PGravite->setSuffix(" N/Kg");
    PGravite->setRange(0.00,234.00);
    PDistance->setSuffix(" m");
    PDistance->setRange(0,15000);
    Temps->setSuffix(" s");
    Temps->setRange(0,5000);
    Force->setSuffix(" N");
    Force->setRange(0,100000);
    Longueur->setSuffix(" m");
    Longueur->setRange(0,1000000);
    Vitesse->setSuffix(" m/s");
    Vitesse->setRange(0,250);
    PFLay1->addRow("Force",Force);
    PFLay1->addRow("Masse",PMasse);
    PFLay1->addRow("Gravite",PGravite);
    PFLay1->addRow("Hauteur",PDistance);
    PFLay1->addRow("Distance",Longueur);
    PFLay7->addRow("Duree",Temps);
    PFLay7->addRow("Vitesse",Vitesse);
}
void Physike::attributs_bas()
{
    PPoids->setSuffix(" N");
    PPoids->setRange(0.0,200000.0);
    PWP->setReadOnly(false);
    PWP->setSuffix(" J");
    PWP->setRange(0.0,50000.0);
    Power->setSuffix(" Watts");
    Power->setRange(0.0,20000.0);
    TravailF->setSuffix(" N");
    TravailF->setRange(0,500000);
    PBLay1->addRow("Travail de la Force",TravailF);
    PBLay1->addRow("Poids",PPoids);
    PBLay1->addRow("Travail du poids",PWP);
    PBLay1->addRow("Puissance",Power);
}

void Physike::attributs_param()
{
    uniteSi->setText("Utiliser le système international");
    uniteSi->setChecked(true);
    unitePerso->setText("Utiliser mon propre systeme d'unite");
    uniteLayout->addWidget(uniteSi);
    uniteLayout->addWidget(unitePerso);
    unitePersoForm->addRow("Unité de puissance",edit1);
    unitePersoForm->addRow("Unité de longueur",edit2);
    unitePersoForm->addRow("Unité de temps",edit3);
    unitePersoForm->addRow("Unité de vitesse",edit4);
    uniteLayout->addLayout(unitePersoForm);
    paramUnite->setLayout(uniteLayout);
    paramUnite->setCheckable(true);
    paramUnite->setChecked(false);
    paramUnite->setTitle("Modifier les unités ?");
    PSettingLay->addWidget(paramUnite);
}

void Physike::attributs_Conv()
{
    CConvertir->setText("Convertir");
    CClear->setText("Tout_Effacer");
    CC->addWidget(CConvertir);
    CC->addWidget(CClear);
    CVitesseK->setRange(0,2000);
    CVitesseK->setSuffix(" Km/H");
    CVitesseM->setRange(0,1500);
    CVitesseM->setSuffix(" M/s");
    CPowerC->setRange(0,50000);
    CPowerC->setSuffix(" Ch");
    CPowerW->setRange(0,100000);
    CPowerW->setSuffix(" Watts");
    CLay3->addRow("Vitesse Km/H",CVitesseK);
    CLay3->addRow("Puissance Watts",CPowerW);
    CLay4->addRow("Vitesse M/s",CVitesseM);
    CLay4->addRow("Puissance Ch",CPowerC);
    CLay1->addLayout(CLay3);
    CLay2->addLayout(CLay4);
    CLay->addLayout(CLay1);
    CLay->addLayout(CC);
    CLay->addLayout(CLay2);
    Convert->setLayout(CLay);
}

void Physike::effacer()
{
    CPowerC->setValue(0);
    CPowerW->setValue(0);
    CVitesseK->setValue(0);
    CVitesseM->setValue(0);
}

void Physike::convertir()//Implementation du convertisseur
{
    if(CVitesseK->value() != 0 && CVitesseM->value() == 0)
    {
        float C1 = (float)((CVitesseK->value())/(coefVitesse));
        CVitesseM->setValue(C1);
    }
    if(CVitesseK->value() == 0 && CVitesseM->value() != 0)
    {
        float C2 = (CVitesseM->value())*(coefVitesse);
        CVitesseK->setValue(C2);
    }
    if(CPowerW->value() != 0 && CPowerC->value() == 0)
    {
        float C3 = (float)((CPowerW->value())/(coefPuissance));
        CPowerC->setValue(C3);
    }
    if(CPowerW->value() == 0 && CPowerC->value() != 0)
    {
        float C4 = (CPowerC->value())*(coefPuissance);
        CPowerW->setValue(C4);
    }
}

void Physike::clear()
{
    PPoids->setValue(0);
    PWP->setValue(0);
    Power->setValue(0);
    TravailF->setValue(0);
    CTemps->setValue(0);
    CIntensite->setValue(0);
    CQElectricite->setValue(0);
    CResistance->setValue(0);
}

void Physike::remplirFluxForce()//Check les differentes fonctions utilisees pour remplir le flux
{
    PFlux->append("Formules utilisees:");
    if(bPoids == true)
    {
        PFlux->append("<strong>Poids</strong> = (masse) <strong> * </strong>(gravite)");
    }
    if(bPower == true)
    {
        PFlux->append("<strong>Puissance</strong> = (Travail_force)<strong> / </strong>(Temps mis)");
    }
    if(bTravailP == true)
    {
        PFlux->append("<strong>Travail du poids</strong> = (Poids) <strong>*</strong> (hauteur)");
    }
    if(bTravailF == true)
    {
        PFlux->append("<strong>Travail de la force</strong> = (force) <strong>*</strong> (longueur)");
    }
    if(bPower2 == true)
    {
        PFlux->append("<strong>Puissance</strong> = (force) <strong>*</strong> (Vitesse)");
    }
    if(bPoids2 == true)
    {
        PFlux->append("<strong>Poids</strong> = (Travail_Poids) <strong>/</strong> (hauteur)");
    }
    if(bPower3 == true)
    {
        PFlux->append("<strong>Puissance</strong> = (Travail_Poids )<strong>/</strong> (Temps)");
    }
    if(bTemps == true)
    {
        PFlux->append("<strong>Temps</strong> = (Travail_Poids) <strong>/</strong> (Puissance)");
    }
    if(bVitesse == true)
    {
        PFlux->append("<strong>Vitesse</strong> = (Puissance) <strong>/</strong> (Force)");
    }
    if(bVitesse2 == true)
    {
        PFlux->append("<strong>Vitesse</strong> = (Puissance) <strong>/</strong> (Poids)");
    }
    if(bVitesse3 == true)
    {
        PFlux->append("<strong>Vitesse</strong> = (Distance) <strong>/</strong> (Temps)");
    }
}

void Physike::genererForce()//Implementation des formules pour la partie sur les forces
{
    bPoids = false;
    bPower = false;
    bTravailP = false;
    bTravailF = false;
    bPower2 = false;
    bPoids2 = false;
    bPower3 = false;
    bTemps = false;
    bTemps2 = false;
    bVitesse = false;
    bVitesse2 = false;
    if(PMasse->value() != 0 && PGravite->value() != 0 && PPoids->value() == 0)
    {
        bPoids = true;
        float P1 = (PMasse->value())*(PGravite->value());
        PPoids->setValue(P1);
    }
    if(PPoids->value() != 0 && PDistance->value() != 0 && PWP->value() == 0)
    {
        bTravailP = true;
        float P2 = ((PPoids->value())*(PDistance->value()));
        PWP->setValue(P2);
    }
    else if(PPoids == 0 && PMasse->value() != 0 && PGravite->value() !=0 && PWP->value() == 0)
    {
        bTravailP = true;
        float P3 = (PMasse->value()*PGravite->value())*PDistance->value();
        PWP->setValue(P3);
    }
    if(Temps->value() != 0 && TravailF->value() != 0 && Power->value() == 0)
    {
        bPower = true;
        float P4 = ((TravailF->value())/(Temps->value()));
        Power->setValue(P4);
    }
    if(Force->value() != 0 && Longueur->value() != 0 && TravailF->value() == 0)
    {
        bTravailF = true;
        float P5 = (Force->value())*(Longueur->value());
        TravailF->setValue(P5);
    }
    if(Force->value() != 0 && Vitesse->value() != 0 && Power->value() == 0)
    {
        bPower2 = true;
        float P6 = (Force->value())*(Vitesse->value());
        Power->setValue(P6);
    }
    if(PWP->value() !=0 && PDistance->value()!= 0 && PPoids->value() == 0)
    {
        bPoids2 = true;
        float P7 = (PWP->value())/(PDistance->value());
        PPoids->setValue(P7);
    }
    if(PWP->value() != 0 && Temps->value() != 0&& Power->value() == 0)
    {
        bPower3 = true;
        float P8 = (PWP->value())/(Temps->value());
        Power->setValue(P8);
    }
    if(PWP->value() != 0 && Power->value() != 0 && Temps->value() == 0)
    {
        bTemps = true;
        float P9 = (PWP->value())/(Power->value());
        Temps->setValue(P9);
    }
    if(TravailF->value() != 0 && Power->value() != 0 && Temps->value() == 0)
    {
        bTemps2 = true;
        float P9 = (TravailF->value())/(Power->value());
        Temps->setValue(P9);
    }
    if(Power->value() != 0 && Force->value() != 0 && Vitesse->value() == 0)
    {
        bVitesse = true;
        float P10 = (Power->value())/(Force->value());
        Vitesse->setValue(P10);
    }
    if(Power->value() != 0 && PPoids->value() != 0 && Vitesse->value() == 0)
    {
        bVitesse2 = true;
        float P11 = (Power->value())/(PPoids->value());
        Vitesse->setValue(P11);
    }
    if(PDistance->value() != 0 && Temps->value() != 0 && Vitesse->value() == 0)
    {
        bVitesse3 = true;
        float P12 = PDistance->value()/Temps->value();
        Vitesse->setValue(P12);
    }
    remplirFluxForce();
}

void Physike::attributsCourants()//Nom_explicite
{
    CTemps->setSuffix(" s");
    CTemps->setRange(0,10000);
    CIntensite->setSuffix(" A");
    CIntensite->setRange(0,25000);
    CQElectricite->setSuffix(" C");
    CQElectricite->setRange(0,20000);
    CResistance->setRange(0,50000);
    CResistance->setSuffix(" ohms");
    CTension->setRange(0,10000);
    CTension->setSuffix(" V");
    CElectron->setRange(0,10000000000);
    GenererCourant->setText("Generer");
    Lay1Courant->addRow("Duree",CTemps);
    Lay1Courant->addRow("Quantite d'electricite",CQElectricite);
    Lay1Courant->addRow("Resistance",CResistance);
    Lay2Courant->addRow("Intensite du courant",CIntensite);
    Lay2Courant->addRow("Tension",CTension);
    LayCourant->addLayout(Lay1Courant);
    LayCourant->addWidget(GenererCourant);
    LayCourant->addLayout(Lay2Courant);
}

void Physike::genererElec()//implementation des formules pour la partie electricite
{
    bTension = false;
    bIntensite = false;
    bETemps = false;
    bQuantite = false;
    if(CQElectricite->value() != 0 && CTemps->value() != 0 && CIntensite->value() == 0)
    {
        bIntensite = true;
        float PC1 = (float)((CQElectricite->value())/(CTemps->value()));
        CIntensite->setValue(PC1);
    }
    if(CQElectricite->value() != 0 && CTemps->value() == 0 && CIntensite->value() != 0)
    {
        bETemps = true;
        float PC2 = (float)((CQElectricite->value())/(CIntensite->value()));
        CTemps->setValue(PC2);
    }
    if(CQElectricite->value() == 0 && CTemps->value() != 0 && CIntensite->value() != 0)
    {
        bQuantite = true;
        float PC3 = (float)((CTemps->value())*(CIntensite->value()));
        CQElectricite->setValue(PC3);
    }
    if(CTension->value() == 0 && CIntensite->value() != 0 && CResistance->value() != 0)
    {
        bTension = true;
        float PC4 = (CResistance->value())*(CIntensite->value());
        CTension->setValue(PC4);
    }
    remplirFluxCourant();
}

void Physike::remplirFluxCourant()
{
    PFlux->clear();
    PFlux->append("Formules utilisees:");
    if(bTension == true)
    {
        PFlux->append("<strong>Tension</strong> = Intensite <strong>*</strong> Resistance");
    }
    if(bIntensite == true)
    {
        PFlux->append("<strong>Intensite du courant </strong> = Quantite d'electricite' <strong>/</strong> Temps");
    }
    if(bETemps == true)
    {
        PFlux->append("<strong>Temps</strong> = Quantite d'electricite <strong>/</strong> Intensite du courant");
    }
    if(bQuantite == true)
    {
        PFlux->append("<strong>Quantite d'electricite</strong> = Temps <strong>*</strong> Intensite du courant");
    }
}

void Physike::clearBas()
{
    PPoids->setValue(0);
    PWP->setValue(0);
    Power->setValue(0);
    TravailF->setValue(0);
}

void Physike::clearHaut()
{
    PMasse->setValue(0);
    PGravite->setValue(0);
    PDistance->setValue(0);
    Temps->setValue(0);
    Force->setValue(0);
    Longueur->setValue(0);
    Vitesse->setValue(0);
}
void Physike::retourZ()//Fonction qui RAZ
{
    PPoids->setValue(0);
    PWP->setValue(0);
    Power->setValue(0);
    TravailF->setValue(0);
    PMasse->setValue(0);
    PGravite->setValue(0);
    PDistance->setValue(0);
    Temps->setValue(0);
    Force->setValue(0);
    Longueur->setValue(0);
    Vitesse->setValue(0);
    bPoids = false;
    bPower = false;
    bTravailP = false;
    bTravailF = false;
    bPower2 = false;
    bPoids2 = false;
    bPower3 = false;
    bTemps = false;
    bTemps2 = false;
    bVitesse = false;
    bVitesse2 = false;
    PFlux->clear();
}
