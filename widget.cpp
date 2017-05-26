#include "widget.h"

Fenetre::Fenetre()
{
    //On implemente les differents elements
    setWindowTitle("Physics-Solver");
    accueil = new QLabel;
    choix = new QGroupBox;
    physique = new QRadioButton;
    chimie = new QRadioButton;
    valider = new QPushButton;
    quitter = new QPushButton;
    droits = new QLabel;
    infos = new QTextEdit;
    logo = new QLabel;
    HLay1 = new QHBoxLayout;
    HLay2 = new QHBoxLayout;
    HLay3 = new QHBoxLayout;
    HLay4 = new QHBoxLayout;
    VLay1 = new QVBoxLayout;
    VLay2 = new QVBoxLayout;
    rim1 = new QVBoxLayout;
    MainLay = new QVBoxLayout;
    //Apres la definition des differents elements on va les personnaliser
    accueil->setText("Bienvenue dans le Physics-Solver de Abedi_Technology\n\n\nVous voulez:");
    physique->setText("faire de la physique ?");
    chimie->setText("faire de la chimie ?");
    valider->setText("C'est Parti !");
    valider->setIcon(QIcon("res/valider.jpg"));
    quitter->setText("Quitter !");
    quitter->setIcon(QIcon("res/sortie.jpg"));
    droits->setText("CopyRight © 2016 Adrien and Ismaila !");
    infos->setHtml("<strong>Version du logiciel</strong> : 1.0.2<p><strong>Version du moteur_Physique</strong> : 1.0.2-alpha<p><strong>Version du moteur_Chimique</strong> : 1.0.2-beta");
    infos->setReadOnly(true);
    logo->setPixmap(QPixmap("res/logo.png"));
    rim1->addWidget(physique);
    rim1->addWidget(chimie);
    choix->setLayout(rim1);
    VLay1->addWidget(accueil);
    VLay1->addWidget(choix);
    VLay2->addWidget(logo);
    VLay2->addWidget(infos);
    HLay1->addWidget(droits);
    HLay2->addWidget(valider);
    HLay2->addWidget(quitter);
    HLay3->addLayout(VLay2);
    HLay3->addLayout(VLay1);
    HLay4->addLayout(HLay1);
    HLay4->addLayout(HLay2);
    MainLay->addLayout(HLay3);
    MainLay->addLayout(HLay4);  
    setLayout(MainLay);
    //On declare les actions directrices
    QObject::connect(valider,SIGNAL(clicked()),this,SLOT(analyse()));
    QObject::connect(quitter,SIGNAL(clicked()),qApp,SLOT(quit()));
}

void Fenetre::analyse()//On verifie le choix de l'utilisateur
{
    if(physique->isChecked() == true)
    {
        newton = new Physike();
        newton->exec();
    }
    if(chimie->isChecked() == true)
    {
        lavoisier = new Chimike();
        lavoisier->exec();
    }
    if(chimie->isChecked() == false && physique->isChecked()==false)
    {
        QMessageBox::critical(this,"Méchant","Pourquoi tu veux pas choisir sniff ??");
    }
}
