#include "4eme-3eme/header/syntheseeudioanimation.h"

SyntheseEudioAnimation::SyntheseEudioAnimation(QWidget *parent, const QPoint &position, const QSize &taille):
    QSfmlCanvas(parent,position,taille)
{
    MySize.x = taille.width();
    MySize.y = taille.height();
    animating = new QTimer();
    OnInit();
}

void SyntheseEudioAnimation::OnInit()
{
    Attributing();
}

void SyntheseEudioAnimation::OnUpdate()
{
    MyUpdate();
    MyDraw();
    timer->start(30);
}
void SyntheseEudioAnimation::MyDraw()
{
    this->clear(sf::Color::Black);
    //Reactifs
    if(synthesed == false)
    {
        this->draw(R_Cov_1);
        this->draw(R_Cov_2);
        this->draw(R_Cov_3);
        this->draw(R_H2_1);
        this->draw(R_H2_2);
        this->draw(R_H2_3);
        this->draw(R_H2_4);
        this->draw(R_O2_1);
        this->draw(R_O2_2);
    }
    else if(synthesed == true)
    {
        this->draw(P_Cov_1);
        this->draw(P_H_1);
        this->draw(P_H_2);
        this->draw(P_O2);
        this->draw(P_Cov_1_2);
        this->draw(P_H_1_2);
        this->draw(P_H_2_2);
        this->draw(P_O2_2);
    }
}
void SyntheseEudioAnimation::MyUpdate()
{
    R_Cov_1.rotate(1);
    R_Cov_2.rotate(-1);
    R_Cov_3.rotate(1);
    P_Cov_1.rotate(1);
    P_Cov_1_2.rotate(-1);
    Positionning();
    Collisioning();
    if(moving == true)
    {
        R_Cov_1.move(V1,V1);
        R_Cov_2.move(V2,V2);
        R_Cov_3.move(V3,V3);
    }
    if(reducing > 15)
        synthesed = true;
}

void SyntheseEudioAnimation::Attributing()
{
    //Reactifs-Molecule1
    R_H2_1.setRadius(10);
    R_H2_1.setFillColor(sf::Color::White);
    R_H2_1.setOrigin(R_H2_1.getRadius(),R_H2_1.getRadius());
    R_H2_2.setRadius(10);
    R_H2_2.setFillColor(sf::Color::White);
    R_H2_2.setOrigin(R_H2_2.getRadius(),R_H2_2.getRadius());
    R_Cov_1.setFillColor(sf::Color::Black);
    R_Cov_1.setSize(sf::Vector2f(20,1));
    R_Cov_1.setOrigin(10,1);
    R_Cov_1.setPosition(100,100);
    //Reactifs-Molecule2
    R_H2_3.setRadius(10);
    R_H2_3.setFillColor(sf::Color::White);
    R_H2_3.setOrigin(R_H2_1.getRadius(),R_H2_1.getRadius());
    R_H2_4.setRadius(10);
    R_H2_4.setFillColor(sf::Color::White);
    R_H2_4.setOrigin(R_H2_2.getRadius(),R_H2_2.getRadius());
    R_Cov_2.setFillColor(sf::Color::Black);
    R_Cov_2.setSize(sf::Vector2f(20,1));
    R_Cov_2.setOrigin(10,1);
    R_Cov_2.setPosition(400,400);
    //Reactifs-Molecule3
    R_O2_1.setRadius(10);
    R_O2_1.setFillColor(sf::Color::Red);
    R_O2_1.setOrigin(R_O2_1.getRadius(),R_O2_1.getRadius());
    R_O2_2.setRadius(10);
    R_O2_2.setFillColor(sf::Color::Red);
    R_O2_2.setOrigin(R_O2_2.getRadius(),R_O2_2.getRadius());
    R_Cov_3.setFillColor(sf::Color::Black);
    R_Cov_3.setSize(sf::Vector2f(20,1));
    R_Cov_3.setOrigin(10,1);
    R_Cov_3.setPosition(250,250);
    //Produits
    P_H_1.setRadius(10);
    P_H_1.setFillColor(sf::Color::White);
    P_H_1.setOrigin(P_H_1.getRadius(),P_H_1.getRadius());
    P_H_2.setRadius(10);
    P_H_2.setFillColor(sf::Color::White);
    P_H_2.setOrigin(P_H_1.getRadius(),P_H_1.getRadius());
    P_O2.setRadius(10);
    P_O2.setFillColor(sf::Color::Red);
    P_O2.setOrigin(P_H_1.getRadius(),P_H_1.getRadius());
    P_Cov_1.setFillColor(sf::Color::Black);
    P_Cov_1.setSize(sf::Vector2f(45,1));
    P_Cov_1.setOrigin(22.5,1);
    P_Cov_1.setPosition(250,250);
    P_H_1_2.setRadius(10);
    P_H_1_2.setFillColor(sf::Color::White);
    P_H_1_2.setOrigin(P_H_1_2.getRadius(),P_H_1_2.getRadius());
    P_H_2_2.setRadius(10);
    P_H_2_2.setFillColor(sf::Color::White);
    P_H_2_2.setOrigin(P_H_1_2.getRadius(),P_H_1_2.getRadius());
    P_O2_2.setRadius(10);
    P_O2_2.setFillColor(sf::Color::Red);
    P_O2_2.setOrigin(P_H_1_2.getRadius(),P_H_1_2.getRadius());
    P_Cov_1_2.setFillColor(sf::Color::Black);
    P_Cov_1_2.setSize(sf::Vector2f(45,1));
    P_Cov_1_2.setOrigin(22.5,1);
    P_Cov_1_2.setPosition(350,350);
}

void SyntheseEudioAnimation::Starting()
{
}
void SyntheseEudioAnimation::Positionning()
{
    //Reactifs
    R_H2_1.setPosition((R_Cov_1.getPosition().x-((R_Cov_1.getSize().x/2)*cos(R_Cov_1.getRotation()*3.14/180))),
                       (R_Cov_1.getPosition().y-((R_Cov_1.getSize().x/2)*sin(R_Cov_1.getRotation()*3.14/180))));
    R_H2_2.setPosition((R_Cov_1.getPosition().x+((R_Cov_1.getSize().x/2)*cos(R_Cov_1.getRotation()*3.14/180))),
                       (R_Cov_1.getPosition().y+((R_Cov_1.getSize().x/2)*sin(R_Cov_1.getRotation()*3.14/180))));
    R_H2_3.setPosition((R_Cov_2.getPosition().x-((R_Cov_2.getSize().x/2)*cos(R_Cov_2.getRotation()*3.14/180))),
                       (R_Cov_2.getPosition().y-((R_Cov_2.getSize().x/2)*sin(R_Cov_2.getRotation()*3.14/180))));
    R_H2_4.setPosition((R_Cov_2.getPosition().x+((R_Cov_2.getSize().x/2)*cos(R_Cov_2.getRotation()*3.14/180))),
                       (R_Cov_2.getPosition().y+((R_Cov_2.getSize().x/2)*sin(R_Cov_2.getRotation()*3.14/180))));
    R_O2_1.setPosition((R_Cov_3.getPosition().x-((R_Cov_3.getSize().x/2)*cos(R_Cov_3.getRotation()*3.14/180))),
                       (R_Cov_3.getPosition().y-((R_Cov_3.getSize().x/2)*sin(R_Cov_3.getRotation()*3.14/180))));
    R_O2_2.setPosition((R_Cov_3.getPosition().x+((R_Cov_3.getSize().x/2)*cos(R_Cov_3.getRotation()*3.14/180))),
                       (R_Cov_3.getPosition().y+((R_Cov_3.getSize().x/2)*sin(R_Cov_3.getRotation()*3.14/180))));
    //Produits
    P_H_1.setPosition((P_Cov_1.getPosition().x+((P_Cov_1.getSize().x/2)*cos(P_Cov_1.getRotation()*3.14/180))),
                       (P_Cov_1.getPosition().y+((P_Cov_1.getSize().x/2)*sin(P_Cov_1.getRotation()*3.14/180))));
    P_H_2.setPosition((P_Cov_1.getPosition().x-((P_Cov_1.getSize().x/2)*cos(P_Cov_1.getRotation()*3.14/180))),
                       (P_Cov_1.getPosition().y-((P_Cov_1.getSize().x/2)*sin(P_Cov_1.getRotation()*3.14/180))));
    P_O2.setPosition(P_Cov_1.getPosition());
    P_H_1_2.setPosition((P_Cov_1_2.getPosition().x+((P_Cov_1_2.getSize().x/2)*cos(P_Cov_1_2.getRotation()*3.14/180))),
                       (P_Cov_1_2.getPosition().y+((P_Cov_1_2.getSize().x/2)*sin(P_Cov_1_2.getRotation()*3.14/180))));
    P_H_2_2.setPosition((P_Cov_1_2.getPosition().x-((P_Cov_1_2.getSize().x/2)*cos(P_Cov_1_2.getRotation()*3.14/180))),
                       (P_Cov_1_2.getPosition().y-((P_Cov_1_2.getSize().x/2)*sin(P_Cov_1_2.getRotation()*3.14/180))));
    P_O2_2.setPosition(P_Cov_1_2.getPosition());

}
void SyntheseEudioAnimation::Collisioning()
{
    //Reactifs
    if(R_Cov_1.getPosition().x > MySize.x || R_Cov_1.getPosition().y > MySize.y ||
       R_Cov_1.getPosition().x < 0 || R_Cov_1.getPosition().y < 0)
        V1 = -V1;
    if(R_Cov_2.getPosition().x > MySize.x || R_Cov_2.getPosition().y > MySize.y ||
       R_Cov_2.getPosition().x < 0 || R_Cov_2.getPosition().y < 0)
        V2 = -V2;
    if(R_Cov_3.getPosition().x > MySize.x || R_Cov_3.getPosition().y > MySize.y ||
       R_Cov_3.getPosition().x < 0 || R_Cov_3.getPosition().y < 0)
    {
        V3 = -V1;
        V3 = -V2;
    }
}
void SyntheseEudioAnimation::setDoesStart(bool newValue)
{
    if(newValue == true)
    {
        doesStart = newValue;
        moving = !newValue;
        R_Cov_1.setPosition(200,200);
        R_Cov_2.setPosition(400,300);
        R_Cov_3.setPosition(400,200);
        QObject::connect(animating,SIGNAL(timeout()),this,SLOT(Scalling()));
        animating->start(500);
    }
    else if(newValue == false)
    {
        doesStart = newValue;
        moving = !newValue;
        synthesed = false;
        reducing = 0;
        Attributing();
        R_Cov_1.setSize(sf::Vector2f(20,1));
        R_Cov_2.setSize(sf::Vector2f(20,1));
        R_Cov_3.setSize(sf::Vector2f(20,1));
        R_H2_1.setScale(1,1);
        R_H2_2.setScale(1,1);
        R_H2_3.setScale(1,1);
        R_H2_4.setScale(1,1);
        R_O2_1.setScale(1,1);
        R_O2_2.setScale(1,1);
        QObject::disconnect(animating,SIGNAL(timeout()),this,SLOT(Scalling()));
    }
}
void SyntheseEudioAnimation::Scalling()
{
    sf::Vector2f newSized;
    newSized.x = R_Cov_1.getSize().x - 1;
    newSized.y = 1;
    R_Cov_1.setSize(newSized);
    R_Cov_2.setSize(newSized);
    R_Cov_3.setSize(newSized);
    R_H2_1.scale(0.8,0.8);
    R_H2_2.scale(0.8,0.8);
    R_H2_3.scale(0.8,0.8);
    R_H2_4.scale(0.8,0.8);
    R_O2_1.scale(0.8,0.8);
    R_O2_2.scale(0.8,0.8);
    animating->start(500);
    reducing++;
}
