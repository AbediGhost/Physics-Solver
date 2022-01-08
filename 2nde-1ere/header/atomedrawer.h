#ifndef ATOMEDRAWER_H
#define ATOMEDRAWER_H

#include "qsfmlcanvas.h"
#include "2nde-1ere/header/atome.h"
#include <cmath>

class AtomeDrawer : public QSfmlCanvas
{
public:
    AtomeDrawer(QWidget *parent,const QPoint &position,const QSize &taille);
    void OnInit();
    void OnUpdate();
private:
    //Fonctions privees
    void MyDraw();
    void MyUpdate();
    void Attributing();
    void EventManage();
    //Attributs prives
    Atome *mAtome;
    sf::RectangleShape lope;
    sf::CircleShape elec1;
    bool update;
    short currentElement;

};

#endif // ATOMEDRAWER_H
