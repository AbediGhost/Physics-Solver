#ifndef TABLEAUPERIODIQUE_H
#define TABLEAUPERIODIQUE_H

#include <QWidget>
#include <QDialog>
#include <QVBoxLayout>
#include <QTextEdit>
#include "2nde-1ere/header/atomedrawer.h"

class TableauPeriodique : public QDialog
{
    Q_OBJECT
public:
    TableauPeriodique(QWidget *parent = 0);
private:
    //flemme
    QVBoxLayout *mainLay;
    AtomeDrawer *ADrawer;
};

#endif // TABLEAUPERIODIQUE_H
