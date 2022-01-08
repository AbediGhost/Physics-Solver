#include "2nde-1ere/header/chimie2nde1ere.h"

Chimie2nde1ere::Chimie2nde1ere()
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
void Chimie2nde1ere::orienter()
{
    if(choiceBox->currentText() == "Tableau_Periodique")
    {
        Mendeleiv = new TableauPeriodique;
        Mendeleiv->show();
    }
}
void Chimie2nde1ere::actualize()
{
}
void Chimie2nde1ere::loadExp()
{
    std::ifstream lecteur("res/Chimie2nde/2ndeListeExp.dat");
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
    lecteur.open("res/Infos/Tableau_PeriodiqueInfo.dat");
    while(lecteur.get(carac))
    {
        informative += carac;
    }
    description->setText(QString::fromStdString(informative));
}
