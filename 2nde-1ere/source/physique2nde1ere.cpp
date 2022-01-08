#include "2nde-1ere/header/physique2nde1ere.h"

Physique2nde1ere::Physique2nde1ere()
{
    //Addressing
    mainLay = new QVBoxLayout;
    choiceBox = new QComboBox;
    valider = new QPushButton;
    description = new QTextEdit;
    //Attributing
    loadExp();
    valider->setText("valider");
    valider->setIcon(QIcon("res/IconeExperience.jpg"));
    mainLay->addWidget(choiceBox);
    mainLay->addWidget(description);
    mainLay->addWidget(valider);
    //Finalling
    setLayout(mainLay);
    setWindowTitle("Chimie 2nde/1ere");
    QObject::connect(valider,SIGNAL(clicked()),this,SLOT(orienter()));
    QObject::connect(choiceBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(actualize()));
}
void Physique2nde1ere::orienter()
{
    if(choiceBox->currentText() == "Circuit_Electrique")
    {
        faraday = new CircuitElectrique;
        faraday->show();
    }
}
void Physique2nde1ere::actualize()
{
}
void Physique2nde1ere::loadExp()
{
    std::ifstream lecteur("res/Physique2nde/2ndeListeExpP.dat");
    std::string tempo;
    char carac = 0;
    std::string informative;
    while(lecteur >> tempo)
    {
        choiceBox->addItem(QString::fromStdString(tempo));
        tempo.clear();
    }
    lecteur.close();
    tempo.clear();
    lecteur.open("res/Infos/Circuit_ElectriqueInfo.dat");
    while(lecteur.get(carac))
    {
        informative += carac;
    }
    description->setText(QString::fromStdString(informative));
}
