#ifndef FENPRINC_H
#define FENPRINC_H

#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QComboBox>
#include <QTextEdit>
#include <QLabel>
#include <fstream>
#include <QString>
#include <vector>
#include <QVBoxLayout>
#include <QTabWidget>
#include <QWidget>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QMessageBox>
#include "syntheseeudio.h"
#include "equation_bilan.h"

class Chimike : public QWidget
{
    Q_OBJECT
public:
    Chimike();
    void attribs();
    void load();
    void loadExperience();
    std::string chargeDonne(std::string fluor);
    void calculsInit();
    void solutionInit();
    void solutionAttribut();
public slots:
    void reload();
    void reloadExp();
    void calculer();
    void LaunchExperience();
    void SaCalculs();
private:
    void init();
    QTextEdit *details;
    QComboBox *atomes;
    QLabel *representation;
    QLabel *nomAtome;
    QHBoxLayout *first;
    QVBoxLayout *secon;
    QHBoxLayout *MainLay;
    QWidget *presentation;
    QWidget *calculs;
    QWidget *experience;
    QWidget *SolutionAqueuse;
    QTabWidget *Princip;
    std::string baseImage;
    std::string baseDetails;
    QDoubleSpinBox *MasseMolaire;
    QDoubleSpinBox *Masse;
    QDoubleSpinBox *Volume;
    QDoubleSpinBox *Moles;
    QDoubleSpinBox *ConcentrationMolaire;
    QDoubleSpinBox *ConcentrationMassique;
    QDoubleSpinBox *VolumeMolaire;
    QFormLayout *LayHaut;
    QFormLayout *LayBas;
    QVBoxLayout *calculsLay;
    QPushButton *start;
    QComboBox *ChoixTest;
    QGroupBox *ChoixMode;
    QVBoxLayout *ChoixModeLay;
    QVBoxLayout *ExpLay;
    QVBoxLayout *ChoixTestLay;
    QHBoxLayout *ExpBasLay;
    QTextEdit *ExpDetails;
    QRadioButton *RouilleFer;
    QRadioButton *ModeGraphique;
    QRadioButton *ModeCalcul;
    QGroupBox *SaSolute;
    QGroupBox *SaSolvant;
    QGroupBox *SaSolution;
    QHBoxLayout *SaFirstLay;
    QVBoxLayout *SALay;
    QFormLayout *SoluteLay;
    QFormLayout *SolvantLay;
    QFormLayout *ResulLay;
    QDoubleSpinBox *SoluteMasse;
    QDoubleSpinBox *SoluteMasseMolaire;
    QDoubleSpinBox *SolutionConcentrationMassique;
    QDoubleSpinBox *SolutionConcentrationMolaire;
    QDoubleSpinBox *SolvantVolume;
    QPushButton *SA_Start;
    QPushButton *LancerExperience;
    SyntheseEudio *Rutherford;
    Equation_Bilan *Lowry;
};

#endif // FENPRINC_H
