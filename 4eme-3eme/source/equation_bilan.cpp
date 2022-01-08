#include "4eme-3eme/header/equation_bilan.h"

Equation_Bilan::Equation_Bilan()
{
    setWindowTitle("Moteur d'equilibrage");
    init();
    attribut();
    setLayout(MainLay);
    QObject::connect(Equilibre,SIGNAL(clicked()),this,SLOT(Start()));
}

void Equation_Bilan::init()
{
    indic1 = new QLabel;
    indic2 = new QLabel;
    Reactif = new QLineEdit;
    fleche = new QLabel;
    Produit = new QLineEdit;
    Equilibre = new QPushButton;
    Resultat = new QLineEdit;
    firstLay = new QHBoxLayout;
    SecLay = new QHBoxLayout;
    FinLay = new QFormLayout;
    MainLay = new QVBoxLayout;
}

void Equation_Bilan::attribut()
{
    indic1->setText("Réactifs");
    indic2->setText("      Produits");
    fleche->setText("  --->  ");
    Equilibre->setText("Equilibrer !");
    Equilibre->setIcon(QIcon("res/IconeExperience.jpg"));
    Resultat->setReadOnly(true);
    firstLay->addWidget(indic1);
    firstLay->addWidget(indic2);
    SecLay->addWidget(Reactif);
    SecLay->addWidget(fleche);
    SecLay->addWidget(Produit);
    FinLay->addRow("Equation_equlibrée :",Resultat);
    MainLay->addLayout(firstLay);
    MainLay->addLayout(SecLay);
    MainLay->addWidget(Equilibre);
    MainLay->addLayout(FinLay);
}

void Equation_Bilan::parse()
{
    std::string reactifStore = Reactif->text().toStdString();
    std::string produitStore = Produit->text().toStdString();
    std::string numberStore;
    std::string atomeStore;
    std::stringstream convert;
    int CoeffTempo=0;
    bool jet = false;
    for(int i=0;i<reactifStore.size();i++)
    {
        if(reactifStore[i] == '^')
            ReacCoeffPos.push_back(i+1);
    }
    for(int i=0;i<produitStore.size();i++)
    {
        if(produitStore[i] == '^')
            ProdCoeffPos.push_back(i+1);
    }
    for(int i=0;i<reactifStore.size();i++)
    {
        if(reactifStore[i] == '^')
        {
            convert <<reactifStore[i+1];
            if( reactifStore[i+2] == '1' || reactifStore[i+2] == '2' || reactifStore[i+2] == '3' ||
                reactifStore[i+2] == '4' || reactifStore[i+2] == '5' || reactifStore[i+2] == '6' ||
                reactifStore[i+2] == '7' || reactifStore[i+2] == '8' || reactifStore[i+2] == '9')
            {
                convert <<reactifStore[i+2];
            }
            convert >> CoeffTempo;
            ReacMap[atomeStore] = CoeffTempo;
            atomeStore.clear();
            CoeffTempo = 0;
            convert.clear();
            continue;
        }
        if(reactifStore[i] == '+')
        {
            ReacMap[atomeStore] = 1;
            atomeStore.clear();
            CoeffTempo = 0;
            convert.clear();
            continue;
        }
        atomeStore+=reactifStore[i];
    }
    atomeStore.clear();
    CoeffTempo = 0;
    convert.clear();
    for(int i=0;i<produitStore.size();i++)
    {
        if(produitStore[i] == '^')
        {
            convert <<produitStore[i+1];
            if( produitStore[i+2] == '1' || produitStore[i+2] == '2' || produitStore[i+2] == '3' ||
                produitStore[i+2] == '4' || produitStore[i+2] == '5' || produitStore[i+2] == '6' ||
                produitStore[i+2] == '7' || produitStore[i+2] == '8' || produitStore[i+2] == '9')
            {
                convert <<produitStore[i+2];
            }
            convert >> CoeffTempo;
            ProdMap[atomeStore] = CoeffTempo;
            atomeStore.clear();
            CoeffTempo = 0;
            convert.clear();
            continue;
        }
        if(reactifStore[i] == '+')
        {
            ProdMap[atomeStore] = 1;
            atomeStore.clear();
            CoeffTempo = 0;
            convert.clear();
            continue;
        }
        atomeStore+=produitStore[i];
    }
    std::stringstream tempoStr;
    std::string ghz;
    std::string hrz;
    for(std::map<std::string,int>::iterator it=ReacMap.begin();it!=ReacMap.end();it++)
    {
        tempoStr << it->first;
        tempoStr << '^';
        tempoStr << it->second;
        tempoStr << '+';
    }
    ghz = tempoStr.str();
    tempoStr.clear();
    tempoStr.flush();
    std::stringstream tempoStra;
    for(std::map<std::string,int>::iterator it=ProdMap.begin();it!=ProdMap.end();it++)
    {
        tempoStra << it->first;
        tempoStra << '^';
        tempoStra << it->second;
        tempoStra << '+';
    }
    ghz.substr(0,ghz.size()-2);
    hrz = tempoStra.str();
    ghz+="--->";
    ghz+=hrz;
    Resultat->setText(QString::fromStdString(ghz));
}

void Equation_Bilan::Start()
{
    this->parse();
}
