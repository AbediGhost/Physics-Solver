#ifndef SYNTHESEEUDIOANIMATION_H
#define SYNTHESEEUDIOANIMATION_H

#include "qsfmlcanvas.h"
#include <cmath>

class SyntheseEudioAnimation : public QSfmlCanvas
{
    Q_OBJECT
public:
    SyntheseEudioAnimation(QWidget *parent,const QPoint &position,const QSize &taille);
    void OnInit();
    void OnUpdate();
    void setDoesStart(bool newValue);
public slots:
    void Scalling();
private:
    //Reactifs
    sf::CircleShape R_H2_1;
    sf::CircleShape R_H2_2;
    sf::CircleShape R_H2_3;
    sf::CircleShape R_H2_4;
    sf::CircleShape R_O2_1;
    sf::CircleShape R_O2_2;
    sf::RectangleShape R_Cov_1;
    sf::RectangleShape R_Cov_2;
    sf::RectangleShape R_Cov_3;

    //Produits
    sf::CircleShape P_H_1;
    sf::CircleShape P_H_2;
    sf::CircleShape P_O2;
    sf::RectangleShape P_Cov_1;
    sf::CircleShape P_H_1_2;
    sf::CircleShape P_H_2_2;
    sf::CircleShape P_O2_2;
    sf::RectangleShape P_Cov_1_2;

    //Fonctions
    void Attributing();
    void Starting();
    void Positionning();
    void Collisioning();
    void MyDraw();
    void MyUpdate();

    //Quelques attributs utiles
    bool doesStart = false;
    bool synthesed = false;
    bool moving = true;
    sf::Vector2f MySize;
    short V1 = 1;
    short V2 = -1;
    short V3 = -1;
    QTimer *animating;
    int reducing = 0;

};

#endif // SYNTHESEEUDIOANIMATION_H
