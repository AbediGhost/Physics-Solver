#ifndef PHYSIQUE2NDE1ERE_H
#define PHYSIQUE2NDE1ERE_H

#include <QWidget>
#include <fstream>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include "2nde-1ere/header/circuitelectrique.h"

class Physique2nde1ere : public QWidget
{
    Q_OBJECT
public:
    Physique2nde1ere();
public slots:
    void orienter();
    void actualize();
private:
    void loadExp();
    //__________
    QVBoxLayout *mainLay;
    QComboBox *choiceBox;
    QPushButton *valider;
    QTextEdit *description;
    CircuitElectrique *faraday;
};

#endif // PHYSIQUE2NDE1ERE_H
