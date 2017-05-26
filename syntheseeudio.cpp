#include "syntheseeudio.h"

SyntheseEudio::SyntheseEudio()
{
    V_H2 = new QDoubleSpinBox(this);
    V_O2 = new QDoubleSpinBox(this);
    M_H2 = new QDoubleSpinBox(this);
    M_O2 = new QDoubleSpinBox(this);
    CNTP = new QDoubleSpinBox(this);
    Resultat = new QFormLayout();
    V_H2O = new QDoubleSpinBox();
    M_H2O = new QDoubleSpinBox();
    SecLay = new QHBoxLayout;
    MainLay = new QVBoxLayout;
    SEVLay = new QFormLayout;
    SEMLay = new QFormLayout;
    StartThink = new QPushButton;
    M_Group = new QGroupBox;
    V_Group = new QGroupBox;
    OtherVariables = new QFormLayout;
    MidLay = new QHBoxLayout;
    Details = new QLineEdit;
    Volume_Restant = 0;
    H_Residuel=false;
    O_Residuel = false;
    initialisation();
    setWindowTitle("Synthese eudiométrique de l'eau");
    setLayout(MainLay);
    QObject::connect(StartThink,SIGNAL(clicked()),this,SLOT(Generer()));
}

void SyntheseEudio::Generer()
{
    if(M_Group->isChecked() && V_Group->isChecked()){
        QMessageBox::critical(this,"Oupss","Les unites choisies sont imprecises !");
        return;
    }
    else if((M_Group->isChecked()) && !(V_Group->isChecked())){
        Synthese_Masse();
        return;
    }
    else if((V_Group->isChecked()) && !(M_Group->isChecked())){
        Synthese_Volume();
        return;
        }
    else{
        QMessageBox::critical(this,"Oupss","Veuillez selectionner le type d'unité à utiliser !");
        return;
    }
}

void SyntheseEudio::initialisation()
{
    V_H2->setSuffix(" L");
    V_O2->setSuffix(" L");
    M_H2->setSuffix(" g");
    M_O2->setSuffix(" g");
    CNTP->setSuffix(" L/mol");
    StartThink->setText("Lancer la synthese !");
    SEVLay->addRow("Volume hydrogene",V_H2);
    SEVLay->addRow("Volume oxygene",V_O2);
    SEMLay->addRow("Masse hydrogene",M_H2);
    SEMLay->addRow("Masse oxygene",M_O2);
    OtherVariables->addRow("Volume molaire",CNTP);
    M_H2O->setSuffix(" g");
    V_H2O->setSuffix(" L");
    M_H2O->setRange(0,10000);
    V_H2O->setRange(0,10000);
    V_H2O->setDecimals(3);
    M_H2O->setDecimals(3);
    Details->setFixedWidth(30);
    Resultat->addRow("Masse d'eau formée :",M_H2O);
    Resultat->addRow("Volume d'eau formé :",V_H2O);
    V_Group->setTitle("Volume");
    V_Group->setCheckable(true);
    M_Group->setTitle("Masse");
    M_Group->setCheckable(true);
    V_Group->setLayout(SEVLay);
    M_Group->setLayout(SEMLay);
    SecLay->addWidget(V_Group);
    SecLay->addWidget(M_Group);
    MidLay->addWidget(StartThink);
    MidLay->addWidget(Details);
    MainLay->addLayout(SecLay);
    MainLay->addLayout(OtherVariables);
    MainLay->addLayout(MidLay);
    MainLay->addLayout(Resultat);
}

void SyntheseEudio::Synthese_Masse()
{
    double Masse_Eau=0,Volume_Eau=0;
    if(CNTP->value() == 0.00){
        QMessageBox::critical(this,"Oupss","Volume molaire inutilisable !!!!");
        return;
    }
    if((M_H2->value() == 0.00) && (M_O2->value() == 0.00)){
        QMessageBox::critical(this,"Oupss","Donnees inutilisables !!!");
        return;
    }
    if(M_O2->value() != 0.00 && M_H2->value() == 0){
        Masse_Eau = (M_O2->value()*18)/16;
        M_H2O->setValue(Masse_Eau);
        Volume_Eau = (Masse_Eau/18)*CNTP->value();
        V_H2O->setValue(Volume_Eau);
    }
    if(M_H2->value() != 0.00 && M_O2->value() == 0){
        Masse_Eau = (M_H2->value()*18)/2;
        M_H2O->setValue(Masse_Eau);
        Volume_Eau = (Masse_Eau/18)*CNTP->value();
        V_H2O->setValue(Volume_Eau);
    }
}

void SyntheseEudio::Synthese_Volume()
{
    double masseH2=0,masseO2=0,masseH2O=0;
    if(CNTP->value() == 0.00){
        QMessageBox::critical(this,"Oupss","Volume molaire inutilisable !!!!");
        return;
    }
    if((V_H2->value()) != 0 && (V_O2->value() == 0)){
         masseH2 = (V_H2->value()/CNTP->value())*1;
         masseH2O = (masseH2*18)/2;
         V_H2O->setValue((masseH2O/18)*CNTP->value());
         M_H2O->setValue(masseH2O);
    }
    else if((V_O2->value() != 0) && (V_H2->value() == 0)){
        masseO2 = (V_O2->value()/CNTP->value())*16;
        masseH2O = (masseO2*18)/16;
        V_H2O->setValue((masseH2O/18)*CNTP->value());
        M_H2O->setValue(masseH2O);
    }
    else if(V_O2->value() != 0 && V_H2->value() != 0)
    {
        if(Details->text() == "H")
        {
            if(V_H2->value() <= V_O2->value())
            {
                masseH2 = (V_H2->value()/CNTP->value())*1;
                masseH2O = (masseH2*18)/2;
                V_H2O->setValue((masseH2O/18)*CNTP->value());
                M_H2O->setValue(masseH2O);
            }
            else if(V_H2->value() > V_O2->value())
            {
                if((((V_H2->value())/2)-V_O2->value())>0)
                {
                    masseH2 = ((V_O2->value()*2)/CNTP->value())*1;
                    masseH2O = (masseH2*18)/2;
                    V_H2O->setValue((masseH2O/18)*CNTP->value());
                    M_H2O->setValue(masseH2O);
                }
            }
        }
        else if(Details->text() == "O")
        {
            if(V_H2->value() <= V_O2->value())
            {
                masseO2 = (V_O2->value()/CNTP->value())*16;
                masseH2O = (masseO2*18)/16;
                V_H2O->setValue((masseH2O/18)*CNTP->value());
                M_H2O->setValue(masseH2O);
            }
            else if(V_H2->value() > V_O2->value())
            {
                if((((V_H2->value())/2)-V_O2->value())>0)
                {
                    masseO2 = ((V_O2->value())/CNTP->value())*16;
                    masseH2O = (masseO2*18)/16;
                    V_H2O->setValue((masseH2O/18)*CNTP->value());
                    M_H2O->setValue(masseH2O);
                }
            }
        }
    }
}
