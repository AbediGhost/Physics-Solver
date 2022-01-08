#include "4eme-3eme/header/fenprinc.h"

Chimike::Chimike()
{
    setWindowTitle("Chimie-Abedi");
    init();
    load();
    calculsInit();
    solutionInit();
    attribs();
    solutionAttribut();
    QObject::connect(atomes,SIGNAL(currentIndexChanged(QString)),this,SLOT(reload()));
    QObject::connect(ChoixTest,SIGNAL(currentIndexChanged(QString)),this,SLOT(reloadExp()));
    QObject::connect(start,SIGNAL(clicked()),this,SLOT(calculer()));
    QObject::connect(LancerExperience,SIGNAL(clicked()),this,SLOT(LaunchExperience()));
    QObject::connect(SA_Start,SIGNAL(clicked()),this,SLOT(SaCalculs()));
    setLayout(MainLay);
}

void Chimike::init()
{
    atomes = new QComboBox;
    details = new QTextEdit;
    representation = new QLabel;
    first = new QHBoxLayout;
    secon = new QVBoxLayout;
    nomAtome = new QLabel;
    presentation = new QWidget;
    calculs = new QWidget;
    experience = new QWidget;
    SolutionAqueuse = new QWidget;
    MainLay = new QHBoxLayout;
    Princip = new QTabWidget;
    //On initialise les variables(chaines de caracteres,constantes)
    baseImage = "res/Chimie/representations/atome";
    baseDetails = "res/Chimie/Details/";
    ChoixTest = new QComboBox;
    ChoixMode = new QGroupBox;
    ExpLay = new QVBoxLayout;
    ChoixTestLay = new QVBoxLayout;
    ExpDetails = new QTextEdit;
    RouilleFer = new QRadioButton;
    ExpBasLay = new QHBoxLayout;
    ModeGraphique = new QRadioButton;
    ModeCalcul = new QRadioButton;
    ChoixModeLay = new QVBoxLayout;
    LancerExperience = new QPushButton(this);
}

void Chimike::load()
{
    std::ifstream listage("res/Chimie/liste/listeAtomes.abe");
    std::string abedi;
    while(listage >> abedi)
    {
        atomes->addItem(QString::fromStdString(abedi));
        abedi.clear();
    }
    listage.close();
    abedi.clear();
    std::ifstream ExpListe("res/Chimie/liste/listeExp.abe");
    while(ExpListe >> abedi)
    {
        ChoixTest->addItem(QString::fromStdString(abedi));
    }
}

std::string Chimike::chargeDonne(std::string fluor)
{
    std::ifstream colgate(fluor.c_str());
    std::string conteneur;
    std::string produit;
    while(getline(colgate,conteneur))
    {
        produit+=conteneur;
        produit+="<p></p>";
    }
    return produit;
}

void Chimike::attribs()
{
    loadExperience();
    details->setReadOnly(true);
    std::string tempo = baseImage + atomes->currentText().toStdString()+".jpg";
    std::string klas = baseDetails + atomes->currentText().toStdString()+".abe";
    details->setText(QString::fromStdString(chargeDonne(klas)));
    representation->setPixmap(QPixmap(QString::fromStdString(tempo)));
    nomAtome->setText("Symbole de l'atome "+atomes->currentText());
    reloadExp();
    secon->addWidget(representation);
    secon->addWidget(nomAtome);
    first->addWidget(atomes);
    first->addWidget(details);
    first->addLayout(secon);
    presentation->setLayout(first);
    calculs->setLayout(calculsLay);
    Princip->addTab(presentation,"Description");
    Princip->addTab(calculs,"Calculator");
    Princip->addTab(experience,"Laboratoire");
    Princip->addTab(SolutionAqueuse,"Solution Aqueuse");
    MainLay->addWidget(Princip);
}

void Chimike::reload()
{
    std::string tempo = baseImage + atomes->currentText().toStdString()+".jpg";
    std::string klas = baseDetails + atomes->currentText().toStdString()+".abe";
    details->setText(QString::fromStdString(chargeDonne(klas)));
    representation->setPixmap(QPixmap(QString::fromStdString(tempo)));
    nomAtome->setText("Symbole de l'atome "+atomes->currentText());
}

void Chimike::calculsInit()
{
    LayHaut = new QFormLayout;
    LayBas = new QFormLayout;
    calculsLay = new QVBoxLayout;
    start = new QPushButton;
    MasseMolaire = new QDoubleSpinBox;
    Masse = new QDoubleSpinBox;
    Volume = new QDoubleSpinBox;
    Moles = new QDoubleSpinBox;
    ConcentrationMolaire = new QDoubleSpinBox;
    ConcentrationMassique = new QDoubleSpinBox;
    VolumeMolaire = new QDoubleSpinBox;
    MasseMolaire->setSuffix(" g/mol");
    MasseMolaire->setRange(0,500);
    Masse->setSuffix(" g");
    Masse->setRange(0,30000);
    Volume->setSuffix(" l");
    Volume->setRange(0,100000);
    Moles->setSuffix(" mol");
    Moles->setRange(0,2000);
    VolumeMolaire->setSuffix(" l/mol");
    VolumeMolaire->setRange(0,100);
    start->setText("Calculer");
    LayHaut->addRow("Masse",Masse);
    LayHaut->addRow("Volume Molaire",VolumeMolaire);
    LayHaut->addRow("Masse Molaire",MasseMolaire);
    LayBas->addRow("Nombre de moles",Moles);
    LayBas->addRow("Volume",Volume);
    calculsLay->addLayout(LayHaut);
    calculsLay->addWidget(start);
    calculsLay->addLayout(LayBas);
}

void Chimike::calculer()
{
    if(Masse->value() != 0 && MasseMolaire->value() != 0 && Moles->value() == 0)
    {
        float C1 = (Masse->value())/(MasseMolaire->value());
        Moles->setValue(C1);
    }
    if(Moles->value() != 0 && VolumeMolaire->value() != 0 && Volume->value() == 0)
    {
        float C2 = (Moles->value())*(VolumeMolaire->value());
        Volume->setValue(C2);
    }
    if(Moles->value() == 0 && Volume->value() != 0 && VolumeMolaire->value() != 0)
    {
        float C5 = (Volume->value())/(VolumeMolaire->value());
        Moles->setValue(C5);
    }
    if(Masse->value() == 0 && Moles->value() != 0 && MasseMolaire->value() != 0)
    {
        float C6 = (Moles->value())*(MasseMolaire->value());
        Masse->setValue(C6);
    }
}

void Chimike::loadExperience()
{
    ModeGraphique->setText("Faire l'experience avec le moteur Graphique !");
    ModeCalcul->setText("Faire l'experience sans le moteur Graphique !");
    LancerExperience->setText("Lancer l'experience !");
    LancerExperience->setIcon(QIcon("res/IconeExperience.jpg"));
    ChoixMode->setLayout(ChoixModeLay);
    ExpDetails->setReadOnly(true);
    //On affiche le tout
    ExpLay->addWidget(ExpDetails);
    ExpLay->addWidget(ChoixTest);
    ExpLay->addWidget(LancerExperience);
    experience->setLayout(ExpLay);
}

void Chimike::LaunchExperience()
{
    if(ChoixTest->currentText() == "Synthese_de_l'eau")
    {
        Rutherford = new SyntheseEudio();
        Rutherford->exec();
    }
    else if(ChoixTest->currentText() == "Equilibrer_des_equations")
    {
        Lowry = new Equation_Bilan();
        Lowry->exec();
    }
    else
    {
        QMessageBox::critical(this,"OUPSSS","Veuillez choisir une expérience à exécuter !!!");
    }
}

void Chimike::reloadExp()
{
    std::string tempo = baseDetails + ChoixTest->currentText().toStdString()+".abe";
    ExpDetails->setText(QString::fromStdString(chargeDonne(tempo)));
}

void Chimike::solutionInit()
{
    SoluteMasse = new QDoubleSpinBox;
    SoluteMasseMolaire = new QDoubleSpinBox;
    SolutionConcentrationMassique = new QDoubleSpinBox;
    SolutionConcentrationMolaire = new QDoubleSpinBox;
    SolvantVolume = new QDoubleSpinBox;
    SA_Start = new QPushButton;
    SaSolute = new QGroupBox;
    SaSolvant = new QGroupBox;
    SaSolution = new QGroupBox;
    SolvantLay = new QFormLayout;
    SoluteLay = new QFormLayout;
    SaFirstLay = new QHBoxLayout;
    ResulLay = new QFormLayout;
    SALay = new QVBoxLayout;
}
void Chimike::solutionAttribut()
{
    //Solute
    SaSolute->setTitle("Solute");
    SoluteMasse->setSuffix(" g");
    SoluteMasse->setRange(0,2000);
    SoluteMasseMolaire->setSuffix(" g/mol");
    SoluteMasseMolaire->setRange(0,2000);
    SoluteLay->addRow("Masse :",SoluteMasse);
    SoluteLay->addRow("MasseMolaire :",SoluteMasseMolaire);
    SaSolute->setLayout(SoluteLay);
    //Solvant
    SaSolvant->setTitle("Solvant");
    SolvantVolume->setSuffix(" l");
    SolvantVolume->setRange(0,100);
    SolvantLay->addRow("Volume :",SolvantVolume);
    SA_Start->setText("Lancer les calculs !");
    SaSolvant->setLayout(SolvantLay);
    //Resultats
    SaSolution->setTitle("Solution");
    SolutionConcentrationMassique->setSuffix(" g/l");
    SolutionConcentrationMassique->setRange(0,10000);
    SolutionConcentrationMolaire->setSuffix(" mol/l");
    SolutionConcentrationMolaire->setRange(0,10000);
    ResulLay->addRow("Concentration molaire :",SolutionConcentrationMolaire);
    ResulLay->addRow("Concentration massique :",SolutionConcentrationMassique);
    SaSolution->setLayout(ResulLay);
    //Finalisation
    SaFirstLay->addWidget(SaSolute);
    SaFirstLay->addWidget(SaSolvant);
    SALay->addLayout(SaFirstLay);
    SALay->addWidget(SA_Start);
    SALay->addWidget(SaSolution);
    SolutionAqueuse->setLayout(SALay);
}

void Chimike::SaCalculs()
{
    if(SoluteMasse->value() != 0 && SolvantVolume->value() != 0 && SolutionConcentrationMassique->value() == 0)
    {
        float S1 = (SoluteMasse->value()/SolvantVolume->value());
        SolutionConcentrationMassique->setValue(S1);
    }
    if(SoluteMasse->value() != 0 && SolvantVolume->value() != 0 && SoluteMasseMolaire->value() != 0 &&
            SolutionConcentrationMassique->value() == 0)
    {
        float S2 = (SoluteMasse->value()/SoluteMasseMolaire->value())/SolvantVolume->value();
        SolutionConcentrationMolaire->setValue(S2);
    }
    if(SolutionConcentrationMolaire->value() != 0 && SoluteMasseMolaire->value() != 0 &&
            SolutionConcentrationMassique->value() == 0)
    {
        float S3 = (SolutionConcentrationMolaire->value()*SoluteMasseMolaire->value());
        SolutionConcentrationMassique->setValue(S3);
    }
    if(SolutionConcentrationMolaire->value() == 0 && SoluteMasseMolaire->value() != 0 &&
            SolutionConcentrationMassique->value() != 0)
    {
        float S4 = (SolutionConcentrationMassique->value()/SoluteMasseMolaire->value());
        SolutionConcentrationMolaire->setValue(S4);
    }
    if(SoluteMasse->value() == 0 && SolvantVolume->value() != 0 && SolutionConcentrationMassique->value() != 0)
    {
        float S5 = (SolutionConcentrationMassique->value()*SolvantVolume->value());
        SoluteMasse->setValue(S5);
    }
}
