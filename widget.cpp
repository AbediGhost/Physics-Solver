#include "widget.h"

Fenetre::Fenetre()
{
    //On implemente les differents elements
    setWindowTitle("Physics-Solver");
    accueil = new QLabel;
    choix = new QGroupBox;
    but1 = new QRadioButton;
    but2 = new QRadioButton;
    but3 = new QRadioButton;
    choixLay = new QVBoxLayout;
    valider = new QPushButton;
    quitter = new QPushButton;
    about = new QPushButton;
    droits = new QLabel;
    infos = new QTextEdit;
    description = new QTextEdit;
    logo = new QLabel;
    descriptIndic = new QLabel;
    HLay1 = new QHBoxLayout;
    HLay2 = new QHBoxLayout;
    HLay3 = new QHBoxLayout;
    HLay4 = new QHBoxLayout;
    VLay1 = new QVBoxLayout;
    VLay2 = new QVBoxLayout;
    MainLay = new QVBoxLayout;
    //Apres la definition des differents elements on va les personnaliser
    accueil->setText("Bienvenue dans le Physics-Solver de Abedi-Technology\n\n\nQue voulez vous faire ? :\n\n");
    but1->setText("Programme de 4eme et 3eme");
    but2->setText("Programme de 2nde et 1ere");
    but3->setText("Forum de discussion");
    choixLay->addWidget(but1);
    choixLay->addWidget(but2);
    choixLay->addWidget(but3);
    choix->setLayout(choixLay);
    valider->setText("C'est Parti !");
    valider->setIcon(QIcon("res/valider.jpg"));
    quitter->setText("Quitter !");
    quitter->setIcon(QIcon("res/sortie.jpg"));
    about->setText(("A propos"));
    about->setIcon(QIcon("res/about.jpg"));
    droits->setText("CopyRight © 2016 Abedi-Technology !");
    infos->setHtml("<strong>Version du logiciel</strong> : 2.0 beta<p> \
                   <strong>Version du moteur_Physique</strong> : 1.0.2-alpha<p> \
                   <strong>Version du moteur_Chimique</strong> : 2.0.-beta<p> ");
    infos->setReadOnly(true);
    logo->setPixmap(QPixmap("res/logo.png"));
    descriptIndic->setText("Description :");
    VLay1->addWidget(accueil);
    VLay1->addWidget(choix);
    VLay1->addWidget(descriptIndic);
    VLay1->addWidget(description);
    VLay2->addWidget(logo);
    VLay2->addWidget(infos);
    HLay1->addWidget(droits);
    HLay2->addWidget(valider);
    HLay2->addWidget(quitter);
    HLay2->addWidget(about);
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
    QObject::connect(about,SIGNAL(clicked()),this,SLOT(aboutUsShow()));
}

void Fenetre::analyse()//On verifie le choix de l'utilisateur
{
    if(but1->isChecked())
    {
        Lavoisier = new QuatriemeTroisieme;
        Lavoisier->show();
    }
    else if(but2->isChecked())
    {
        Newton = new SecondePremiere;
        Newton->show();
    }
    else if(but3->isChecked())
    {
        Wahab = new Forum;
        Wahab->show();
    }
}
void Fenetre::aboutUsShow()
{
    aPropos = new  AboutUs;
    aPropos->show();
}

void Fenetre::checkRegistered()
{
    std::ifstream verify("res/Donnees/AlreadyUsed.dat");
    std::string checkSum;
    verify >> checkSum;
    if(verify == "oui")
        loadData();
    else if(verify == "non")
        registering();
}
void Fenetre::loadData()
{

}
void Fenetre::registering()
{

}
