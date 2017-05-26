#ifndef SYNTHESEEUDIO_H
#define SYNTHESEEUDIO_H

#include <QDoubleSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QDialog>
#include <QRadioButton>
#include <QGroupBox>
#include <QMessageBox>
#include <QLineEdit>

class SyntheseEudio : public QDialog
{
    Q_OBJECT
public:
    SyntheseEudio();
    void Synthese_Masse();
    void Synthese_Volume();
public slots:
    void Generer();
private:
    void initialisation();
    QDoubleSpinBox *V_H2;
    QDoubleSpinBox *V_O2;
    QDoubleSpinBox *CNTP;
    QVBoxLayout *MainLay;
    QHBoxLayout *SecLay;
    QFormLayout *SEVLay;
    QFormLayout *SEMLay;
    QFormLayout *OtherVariables;
    QPushButton *StartThink;
    QDoubleSpinBox *M_H2;
    QDoubleSpinBox *M_O2;
    QDoubleSpinBox *V_H2O;
    QDoubleSpinBox *M_H2O;
    QGroupBox *M_Group;
    QGroupBox *V_Group;
    QFormLayout *Resultat;
    QHBoxLayout *MidLay;
    QLineEdit *Details;
    double Volume_Restant;
    bool H_Residuel,O_Residuel;
};

#endif // SYNTHESEEUDIO_H
