#include "2nde-1ere/header/tableauperiodique.h"

TableauPeriodique::TableauPeriodique(QWidget *parent) : QDialog(parent)
{
    const QPoint pos(10,10);
    const QSize taille(600,600);
    this->resize(600,600);
    mainLay = new QVBoxLayout;
    ADrawer = new AtomeDrawer(this,pos,taille);
    mainLay->addWidget(ADrawer);
    ADrawer->show();
    setLayout(mainLay);
    setWindowTitle("Tableau périodique");
}
