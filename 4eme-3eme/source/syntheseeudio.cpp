#include "4eme-3eme/header/syntheseeudio.h"

SyntheseEudio::SyntheseEudio()
{
    const QPoint pos(0,0);
    const QSize taille(500,500);
    this->resize(600,600);
    MainLay = new QVBoxLayout;
    Demarrer = new QPushButton;
    RAZ = new QPushButton;
    Animation = new SyntheseEudioAnimation(this,pos,taille);
    initialisation();
    setWindowTitle("Synthese eudiométrique de l'eau");
    setLayout(MainLay);
    QObject::connect(Demarrer,SIGNAL(clicked()),this,SLOT(DemarrerExp()));
    QObject::connect(RAZ,SIGNAL(clicked()),this,SLOT(StopExp()));
}

void SyntheseEudio::initialisation()
{
    Demarrer->setText("Demarrer la simulation");
    RAZ->setText("Recommencer");
    MainLay->addWidget(Animation);
    MainLay->addWidget(Demarrer);
    MainLay->addWidget(RAZ);
    Animation->show();
}
void SyntheseEudio::DemarrerExp()
{
    Animation->setDoesStart(true);
}
void SyntheseEudio::StopExp()
{
    Animation->setDoesStart(false);
}
