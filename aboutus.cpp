#include "aboutus.h"

AboutUs::AboutUs(QWidget *parent) : QWidget(parent)
{
    information = new QLabel;
    mainLay = new QVBoxLayout;
    load();
    mainLay->addWidget(information);
    setLayout(mainLay);
    setWindowTitle("About Us");
}
void AboutUs::load()
{
    information->setText("\n\n\n\n"
                         "_______________________________Réalisé par Abedi-Technology___________________________\n\n\n"
                         "_______________________________Progammeurs :                    Adrien Faye___________________________________\n"
                         "\n\n\n\n\n\n");
}
