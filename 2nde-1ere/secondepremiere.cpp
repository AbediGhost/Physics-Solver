#include "secondepremiere.h"

SecondePremiere::SecondePremiere(QWidget *parent) : QWidget(parent)
{
    initialisation();
    attribution();
    setLayout(mainLay);
    setWindowTitle("2nde/1ere");
    resize(500,500);
}
void SecondePremiere::initialisation()
{
    mainLay = new QVBoxLayout;
    mainWid = new QTabWidget;
    Rosen = new Physique2nde1ere;
    Boyle = new Chimie2nde1ere;
}
void SecondePremiere::attribution()
{
    mainWid->addTab(Rosen,"Physique");
    mainWid->addTab(Boyle,"Chimie");
    mainLay->addWidget(mainWid);
}
