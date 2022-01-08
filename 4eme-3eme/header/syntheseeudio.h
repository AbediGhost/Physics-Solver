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
#include <QPoint>
#include <QSize>
#include <QMessageBox>
#include "syntheseeudioanimation.h"

class SyntheseEudio : public QDialog
{
    Q_OBJECT
public:
    SyntheseEudio();
public slots:
    void DemarrerExp();
    void StopExp();
private:
    //Variables privees
    void initialisation();
    QVBoxLayout *MainLay;
    QPushButton *Demarrer;
    QPushButton *RAZ;
    SyntheseEudioAnimation *Animation;
};

#endif // SYNTHESEEUDIO_H
