#ifndef CIRCUITSETTER_H
#define CIRCUITSETTER_H

#include <QWidget>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QDialog>
#include <QLineEdit>
#include <QFormLayout>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QPushButton>

class CircuitSetter : public QDialog
{
    Q_OBJECT
public:
    CircuitSetter(QWidget *parent = 0);
private:
    void attributing();
    void setting();
    //_______
    QVBoxLayout *mainLay;
    QGroupBox *paramGeneraux;
    QGroupBox *paramGenerateur;
    QGroupBox *paramDipoleUn;
    QGroupBox *paramDipoleDeux;
    QFormLayout *paramGenerauxlay;
    QFormLayout *paramGenerateurlay;
    QFormLayout *paramDipoleUnlay;
    QFormLayout *paramDipoleDeuxlay;
    QLineEdit *nameText;
    QLineEdit *generatorNameText;
    QLineEdit *dipoleUnNameText;
    QLineEdit *dipoleDeuxNameText;
    QDoubleSpinBox *generateurFEM;
    QDoubleSpinBox *dipoleUnFCEM;
    QDoubleSpinBox *dipoleDeuxFCEM;
    QDoubleSpinBox *generateurResistance;
    QDoubleSpinBox *dipoleUnResistance;
    QDoubleSpinBox *dipoleDeuxResistance;
    QComboBox *typeBox;
    QPushButton *valider;
};

#endif // CIRCUITSETTER_H
