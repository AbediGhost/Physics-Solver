#include "quatriemetroisieme.h"

QuatriemeTroisieme::QuatriemeTroisieme(QWidget *parent) : QWidget(parent)
{
    setWindowTitle("4eme / 3eme");
    load();
    setting();
    setLayout(mainLay);
}
void QuatriemeTroisieme::load()
{
    mainWid = new QTabWidget;
    physique = new Physike;
    chimie = new Chimike;
    mainLay = new QVBoxLayout;
}
void QuatriemeTroisieme::setting()
{
    mainWid->addTab(physique,"Physique");
    mainWid->addTab(chimie,"Chimie");
    mainLay->addWidget(mainWid);
}
