#ifndef CHIMIE2NDE1ERE_H
#define CHIMIE2NDE1ERE_H

#include <QWidget>
#include <fstream>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QTextEdit>
#include "2nde-1ere/header/tableauperiodique.h"

class Chimie2nde1ere : public QWidget
{
    Q_OBJECT
public:
    Chimie2nde1ere();
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
    TableauPeriodique *Mendeleiv;
};

#endif // CHIMIE2NDE1ERE_H
