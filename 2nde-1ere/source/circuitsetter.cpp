#include "2nde-1ere/header/circuitsetter.h"

CircuitSetter::CircuitSetter(QWidget *parent) : QDialog(parent)
{
    attributing();
    setting();
    setLayout(mainLay);
    setWindowTitle("Parametres du circuit");
    this->setModal(true);
}
void CircuitSetter::attributing()
{
    //ParamGeneraux
    paramGeneraux = new QGroupBox;
    paramGenerateur = new QGroupBox;
    paramDipoleUn = new QGroupBox;
    paramDipoleDeux = new QGroupBox;
    paramGenerauxlay = new QFormLayout;
    paramGenerateurlay = new QFormLayout;
    paramDipoleUnlay = new QFormLayout;
    paramDipoleDeuxlay = new QFormLayout;
    nameText = new QLineEdit;
    generatorNameText = new QLineEdit;
    dipoleUnNameText = new QLineEdit;
    dipoleDeuxNameText = new QLineEdit;
    generateurFEM = new QDoubleSpinBox;
    dipoleUnFCEM = new QDoubleSpinBox;
    dipoleDeuxFCEM = new QDoubleSpinBox;
    generateurResistance = new QDoubleSpinBox;
    dipoleUnResistance = new QDoubleSpinBox;
    dipoleDeuxResistance = new QDoubleSpinBox;
    typeBox = new QComboBox;
    valider = new QPushButton;
    //Main
    mainLay = new QVBoxLayout;
}
void CircuitSetter::setting()
{
    typeBox->addItem("Circuit en dérivation");
    typeBox->addItem("Circuit en série");
    paramGeneraux->setLayout(paramGenerauxlay);
    paramGeneraux->setTitle("Parametres generaux du circuit");
    paramGenerauxlay->addRow("Nom du circuit : ",nameText);
    paramGenerauxlay->addRow("Configuration du circuit : ",typeBox);
    //______________
    generateurFEM->setSuffix(" volts");
    generateurResistance->setSuffix(QString::fromStdString(" ohms"));
    paramGenerateur->setLayout(paramGenerateurlay);
    paramGenerateur->setTitle("Parametres du generateur");
    paramGenerateurlay->addRow("Nom : ",generatorNameText);
    paramGenerateurlay->addRow("Force electromotrice : ",generateurFEM);
    paramGenerateurlay->addRow("Resistance interne : ",generateurResistance);
    //______________
    dipoleUnFCEM->setSuffix(" volts");
    dipoleUnResistance->setSuffix(" ohms");
    paramDipoleUn->setLayout(paramDipoleUnlay);
    paramDipoleUn->setTitle("Parametres du dipole 1");
    paramDipoleUnlay->addRow("Nom : ",dipoleUnNameText);
    paramDipoleUnlay->addRow("Force contreelectromotrice : ",dipoleUnFCEM);
    paramDipoleUnlay->addRow("Resistance interne : ",dipoleUnResistance);
    //______________
    dipoleDeuxFCEM->setSuffix(QString::fromStdString(" volts"));
    dipoleDeuxResistance->setSuffix(QString::fromStdString(" ohms"));
    paramDipoleDeux->setCheckable(true);
    paramDipoleDeux->setLayout(paramDipoleDeuxlay);
    paramDipoleDeux->setTitle("Parametres du dipole 2");
    paramDipoleDeuxlay->addRow("Nom : ",dipoleDeuxNameText);
    paramDipoleDeuxlay->addRow("Force contreelectromotrice : ",dipoleDeuxFCEM);
    paramDipoleDeuxlay->addRow("Resistance interne : ",dipoleDeuxResistance);
    valider->setText("valider");
    valider->setIcon(QIcon("res/valider.jpg"));
    //______________
    mainLay->addWidget(paramGeneraux);
    mainLay->addWidget(paramGenerateur);
    mainLay->addWidget(paramDipoleUn);
    mainLay->addWidget(paramDipoleDeux);
    mainLay->addWidget(valider);
}
